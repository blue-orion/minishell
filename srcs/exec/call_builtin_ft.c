/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_builtin_ft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:59:01 by takwak            #+#    #+#             */
/*   Updated: 2025/03/12 22:22:39 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	call_builtin_ft(char **cmd, t_cmd *info)
{
	if (!ft_strncmp(cmd[0], "cd", 3))
		g_exit_status = ft_cd(cmd, info);
	if (!ft_strncmp(cmd[0], "echo", 5))
		g_exit_status = ft_echo(cmd);
	if (!ft_strncmp(cmd[0], "env", 4))
		g_exit_status = ft_env(cmd, info->envp);
	if (!ft_strncmp(cmd[0], "exit", 5))
		g_exit_status = ft_exit(cmd, info);
	if (!ft_strncmp(cmd[0], "export", 7))
		g_exit_status = ft_export(cmd, info);
	if (!ft_strncmp(cmd[0], "pwd", 4))
		g_exit_status = ft_pwd(cmd);
	if (!ft_strncmp(cmd[0], "unset", 6))
		g_exit_status = ft_unset(cmd, info);
}
