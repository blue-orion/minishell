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
	while (1)
	{
		readline("minishell> ");
		if (!rl_line_buffer)
			return (1);
		parsing(rl_line_buffer);
		printf("%s\n", rl_line_buffer);
		// 입력받아서 파싱
		// 파싱한 명령어 배열 실행
	}
}
