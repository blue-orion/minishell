/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_signal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:13:02 by takwak            #+#    #+#             */
/*   Updated: 2025/02/26 18:19:37 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SIGNAL_H
# define MINI_SIGNAL_H

# include <signal.h>

typedef struct s_sig
{
	sigset_t	set;
	siginfo_t	info;
}	t_sig;

void	signal_setup(void);
void	handler_sigint(struct sigaction *sa);
#endif
