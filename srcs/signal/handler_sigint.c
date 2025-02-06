/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_sigint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:17:05 by takwak            #+#    #+#             */
/*   Updated: 2025/02/06 18:17:05 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_signal.h"
#include <readline/readline.h>
#include <unistd.h>

void	new_prompt(int signo)
{
	if (signo != SIGINT)
		return ;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

void	handler_sigint(struct sigaction *sa)
{
	sigset_t	block;

	sigemptyset(&block);
	sa->sa_handler = new_prompt;
	sa->sa_mask = block;
}
