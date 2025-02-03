/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 01:29:04 by takwak            #+#    #+#             */
/*   Updated: 2025/02/03 20:42:29 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(void)
{
	t_cmd	cmd;
	char	*input;

	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			return (1);
		cmd.root = parsing(input);
		// 입력받아서 파싱
		print_tree(cmd.root);
		printf("\n\n");
		// parsing tree 기반으로 실행
		treeclear(cmd.root);
	}
}
