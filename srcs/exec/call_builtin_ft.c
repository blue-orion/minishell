/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_builtin_ft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:59:01 by takwak            #+#    #+#             */
/*   Updated: 2025/02/12 18:36:39 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

int	call_builtin_ft(char **cmd, t_cmd *info)
{
	int	status;

	if (!ft_strncmp(cmd[0], "cd", 3))
		status = ft_cd(cmd);
	if (!ft_strncmp(cmd[0], "echo", 5))
		status = ft_echo(cmd);
	if (!ft_strncmp(cmd[0], "env", 4))
		status = ft_env(cmd, info->envp);
	if (!ft_strncmp(cmd[0], "exit", 5))
		status = ft_exit(cmd);
	if (!ft_strncmp(cmd[0], "export", 7))
		status = ft_export(cmd, info);
	if (!ft_strncmp(cmd[0], "pwd", 4))
		status = ft_pwd(cmd);
	if (!ft_strncmp(cmd[0], "unset", 6))
		status = ft_unset(cmd, info);
	return (status);
}
