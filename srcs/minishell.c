/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 01:29:04 by takwak            #+#    #+#             */
/*   Updated: 2025/02/09 22:16:00 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(void)
{
	t_cmd	info;
	char	*input;

	signal_setup();
	init_info(&info);
	while (1)
	{
		info.parent = NULL;
		dup2(info.stdfd[INPUT], 0);
		dup2(info.stdfd[OUTPUT], 1);
		input = readline("minishell> ");
		if (!input)
			return (1);
		else
			add_history(input);
		info.root = parsing(input);
		if (!info.root)
			continue ;
		print_tree(info.root);
		printf("\n\n");
		exec_tree_node(&info, info.root);
		treeclear(info.root);
		rl_on_new_line();
	}
	sleep(3);
}
