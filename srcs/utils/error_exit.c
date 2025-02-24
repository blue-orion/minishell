/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:10:54 by takwak            #+#    #+#             */
/*   Updated: 2025/02/24 18:22:34 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/libft.h"
#include <errno.h>

void	error_exit(char *msg)
{
	if (errno)
		perror(msg);
	else
	{
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
	exit(errno);
}
