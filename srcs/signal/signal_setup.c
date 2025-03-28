/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:12:46 by jiwnam            #+#    #+#             */
/*   Updated: 2025/03/28 20:50:04 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_signal.h"

void	signal_setup(t_cmd *info)
{
	struct sigaction	new;

	info = info;
	handler_sigint(&new);
	sigaction(SIGINT, &new, NULL);
	signal(SIGQUIT, SIG_IGN);
}
