/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 01:29:04 by takwak            #+#    #+#             */
/*   Updated: 2025/01/20 01:29:04 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(void)
{
	char	*cmd;

	while (1)
	{
		cmd = readline("minishell> ");
		if (!cmd)
			return (1);
		parsing(cmd);
		// printf("%s\n", rl_line_buffer);
		// 입력받아서 파싱
		// 파싱한 명령어 배열 실행
	}
}
