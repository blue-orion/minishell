/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:15:35 by takwak            #+#    #+#             */
/*   Updated: 2025/03/12 15:06:03 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

int	ft_echo(char **cmd)
{
	int	i;
	int	option;

	option = 0;
	i = 1;
	if (cmd[1] && !ft_strncmp(cmd[1], "-n", 2))
	{
		i++;
		option = 1;
	}
	while (cmd[i])
	{
		write(1, cmd[i], ft_strlen(cmd[i]));
		if (cmd[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (!option)
		write(1, "\n", 1);
	return (0);
}
