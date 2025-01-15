/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 05:43:11 by takwak            #+#    #+#             */
/*   Updated: 2025/01/02 23:20:46 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int	main(void)
{
	while (1)
	{
		readline("minishell> ");
		if (rl_line_buffer)
			return (1);
		//입력받아서 파싱
		//파싱한 명령어 배열 실행
	}
}
