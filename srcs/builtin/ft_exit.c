/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:41:05 by takwak            #+#    #+#             */
/*   Updated: 2025/02/07 22:41:05 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"
#include "../../includes/utils.h"

int	check_valid(char *str);

int	ft_exit(char **cmd)
{
	int	size;
	int	exit_status;

	ft_putendl_fd("exit", 1);
	size = getsize(cmd);
	if (size > 2)
	{
		put_error_msg("exit", NULL, "too many arguments");
		return (1);
	}
	exit_status = ft_atoi(cmd[1]);
	if (check_valid(cmd[1]))
	{
		put_error_msg("exit", cmd[1], "numeric arguments required");
		exit_status = 2;
	}
	exit(exit_status);
}

int	check_valid(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	return (0);
}
