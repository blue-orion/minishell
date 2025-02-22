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

int	main(int ac, char **av, char **env)
{
	t_cmd	info;
	char	*input;
	int		i;

	signal_setup();
	init_info(&info, env);
	while (1)
	{
		info.parent = NULL;
		info.pipe_flag = 0;
		info.input_buf = NULL;
		dup2(info.stdfd[INPUT], 0);
		dup2(info.stdfd[OUTPUT], 1);
		input = readline("minishell> ");
		if (!input)
			break ;
		input = add_newline(input);
		info.cmd_buf = ft_split(input, '\n');
		free(input);
		i = 0;
		while (info.cmd_buf[i])
		{
			input = preprocess_string(&info, *info.cmd_buf);
			info.root = parsing(input);
			if (!info.root)
			{
				i++;
				continue ;
			}
			// print_tree(info.root);
			// printf("\n\n");
			info.input_buf = ft_strdup(*info.cmd_buf);
			i++;
			exec_tree_node(&info, info.root);
			treeclear(info.root);
		}
		if (info.input_buf)
		{
			add_history(make_history(info.input_buf));
			unlink("tmp.txt");
		}
		free(info.input_buf);
		free_pptr((void **)info.cmd_buf);
		rl_on_new_line();
	}
	clear_history();
	ft_free_resource(&info);
	return (0);
}
