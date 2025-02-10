/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:34:22 by takwak            #+#    #+#             */
/*   Updated: 2025/02/10 15:36:59 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	put_error_msg(char *cmd, char *arg, char *error_msg)
{
	ft_putstr_fd("minishell", 2);
	write(2, ": ", 2);
	ft_putstr_fd(cmd, 2);
	write(2, ": ", 2);
	if (arg)
	{
		ft_putstr_fd(arg, 2);
		write(2, ": ", 2);
	}
	ft_putendl_fd(error_msg, 2);
}
