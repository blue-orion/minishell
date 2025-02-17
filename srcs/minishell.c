/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 01:29:04 by takwak            #+#    #+#             */
/*   Updated: 2025/02/15 17:32:33 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_cmd	info;
	char	*input;

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
		while (*info.cmd_buf)
		{
			input = preprocess_string(&info, *info.cmd_buf);
			info.root = parsing(input);
			if (!info.root)
			{
				info.cmd_buf++;
				continue ;
			}
			// print_tree(info.root);
			// printf("\n\n");
			info.input_buf = ft_strdup(*info.cmd_buf);
			info.cmd_buf++;
			exec_tree_node(&info, info.root);
			treeclear(info.root);
		}
		if (info.input_buf)
		{
			add_history(make_history(info.input_buf));
			unlink("tmp.txt");
		}
		rl_on_new_line();
	}
	clear_history();
	return (0);
}
