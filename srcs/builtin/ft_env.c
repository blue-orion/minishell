/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:40:31 by takwak            #+#    #+#             */
/*   Updated: 2025/02/07 22:40:31 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	ft_env(char **cmd, char **envp)
{
	int	i;

	if (cmd[1])
	{
		put_error_msg("env", NULL, "too many arguments");
		return (1);
	}
	else
	{
		i = 0;
		while (envp[i])
		{
			ft_putendl_fd(envp[i], 1);
			i++;
		}
	}
	return (0);
}
