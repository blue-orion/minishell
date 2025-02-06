/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:13:02 by takwak            #+#    #+#             */
/*   Updated: 2025/02/06 15:28:37 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

# include <signal.h>

typedef struct s_sig
{
	sigset_t	set;
	siginfo_t	info;
}	t_sig;

void	signal_setup(void);
void	handler_sigint(struct sigaction *sa);
#endif
