/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_builtin_ft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:59:01 by takwak            #+#    #+#             */
/*   Updated: 2025/03/12 16:44:38 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	call_builtin_ft(char **cmd, t_cmd *info)
{
	if (!ft_strncmp(cmd[0], "cd", 3))
		ft_cd(cmd, info);
	if (!ft_strncmp(cmd[0], "echo", 5))
		ft_echo(cmd);
	if (!ft_strncmp(cmd[0], "env", 4))
		ft_env(cmd, info->envp);
	if (!ft_strncmp(cmd[0], "exit", 5))
		ft_exit(cmd, info);
	if (!ft_strncmp(cmd[0], "export", 7))
		ft_export(cmd, info);
	if (!ft_strncmp(cmd[0], "pwd", 4))
		ft_pwd(cmd);
	if (!ft_strncmp(cmd[0], "unset", 6))
		ft_unset(cmd, info);
}
