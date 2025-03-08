/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 01:29:04 by takwak            #+#    #+#             */
/*   Updated: 2025/03/08 22:07:26 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_setting(t_cmd *info);
void	parse_input_and_exec(t_cmd *info, char *input);

int	main(int ac, char **av, char **env)
{
	t_cmd	info;
	char	*input;
	char	*history;

	signal_setup();
	init_info(&info, env);
	while (1)
	{
		init_setting(&info);
		input = readline("minishell> ");
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
	}
	end_minishell(&info);
	return (0);
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
		info->root = parsing(info->cmd_buf[info->buf_idx]);
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
