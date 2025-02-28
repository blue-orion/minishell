/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_fail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:08:15 by takwak            #+#    #+#             */
/*   Updated: 2025/02/28 16:16:19 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	execve_fail(t_cmd *info, char *cmd, char *error_msg, int status)
{
	int	error_len;

	error_len = ft_strlen(error_msg);
	end_process(info);
	if (!ft_strncmp(error_msg, CMD_NOT_FOUND, error_len))
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(error_msg, 2);
		free_pptr((void **)info->cmd);
		exit(status);
	}
	put_error_msg(cmd, NULL, error_msg);
	free_pptr((void **)info->cmd);
	exit(status);
}
