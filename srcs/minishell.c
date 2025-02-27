/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 01:29:04 by takwak            #+#    #+#             */
/*   Updated: 2025/02/22 18:49:27 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_setting(t_cmd *info);
void	parse_input_and_exec(t_cmd *info, char *input);

int	main(int ac, char **av, char **env)
{
	t_cmd	info;
	char	*input;
	int		i;

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
			add_history(make_history(info.input_buf));
			free(info.input_buf);
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
	int		i;

	input = add_newline(input);
	info->cmd_buf = ft_split(input, '\n');
	free(input);
	i = 0;
	while (info->cmd_buf[i])
	{
		info->root = parsing(info->cmd_buf[i]);
		if (!info->root)
		{
			i++;
			continue ;
		}
		info->input_buf = ft_strdup(info->cmd_buf[i]);
		exec_tree_node(info, info->root);
		treeclear(info->root);
		i++;
	}
	free_pptr((void **)info->cmd_buf);
}
