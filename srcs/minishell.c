/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 01:29:04 by takwak            #+#    #+#             */
/*   Updated: 2025/03/12 20:35:18 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_setting(t_cmd *info);
void	parse_input_and_exec(t_cmd *info, char *input);
char	*get_prompt(t_cmd *info);
void	start_minishell(t_cmd *info, int ac, char **av, char **env);
int		g_exit_status;

int	main(int ac, char **av, char **env)
{
	t_cmd	info;
	char	*input;

	start_minishell(&info, ac, av, env);
	while (1)
	{
		init_setting(&info);
		input = readline(get_prompt(&info));
		if (!input)
			break ;
		parse_input_and_exec(&info, input);
		if (info.input_buf)
		{
			add_history(info.history);
			free(info.history);
			info.history = NULL;
			free(info.input_buf);
			info.input_buf = NULL;
		}
		rl_on_new_line();
		rl_replace_line("", 1);
	}
	end_minishell(&info);
	return (g_exit_status);
}

char	*get_prompt(t_cmd *info)
{
	char	path[4096];
	char	*home;

	free(info->prompt);
	getcwd(path, 4096);
	home = ft_getenv("HOME", info->envp);
	if (!ft_strncmp(path, home, ft_strlen(home)))
		info->prompt = ft_strjoin("~", path + ft_strlen(home));
	else
		info->prompt = ft_strdup(path);
	if (!info->prompt)
		error_exit("malloc failed");
	info->prompt = ft_join_free(info->prompt, "$ ");
	return (info->prompt);
}

void	init_setting(t_cmd *info)
{
	info->parent = NULL;
	info->pipe_flag = 0;
	info->input_buf = NULL;
	dup2(info->stdfd[INPUT], 0);
	dup2(info->stdfd[OUTPUT], 1);
}

void	parse_input_and_exec(t_cmd *info, char *input)
{
	input = add_newline(input);
	info->cmd_buf = ft_split(input, '\n');
	free(input);
	info->buf_idx = 0;
	while (info->cmd_buf[info->buf_idx])
	{
		info->root = parsing(info->cmd_buf[info->buf_idx], info);
		if (!info->root)
		{
			info->buf_idx++;
			continue ;
		}
		free(info->input_buf);
		free(info->history);
		info->input_buf = ft_strdup(info->cmd_buf[info->buf_idx++]);
		exec_tree_node(info, info->root);
		info->history = make_history(info->input_buf);
		treeclear(info->root);
	}
	free_pptr((void **)info->cmd_buf);
}

void	start_minishell(t_cmd *info, int ac, char **av, char **env)
{
	if (ac > 1 || av[1])
		return ;
	print_opening_phrase();
	signal_setup(info);
	init_info(info, env);
}
