/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 01:29:04 by takwak            #+#    #+#             */
/*   Updated: 2025/02/06 15:21:30 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(void)
{
	t_cmd	info;
	char	*input;

	signal_setup();
	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			return (1);
		else
			add_history(input);
		info.root = parsing(input);
		print_tree(info.root);
		printf("\n\n");
		exec_parsing_tree(&info, info.root);
		treeclear(info.root);
		rl_on_new_line();
	}
	sleep(3);
}
