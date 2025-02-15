/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:05:40 by takwak            #+#    #+#             */
/*   Updated: 2025/02/10 15:29:34 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

char	*make_path_cmd(char *path, char *cmd)
{
	char	*new;
	char	*past;

	past = ft_strjoin(path, "/");
	new = ft_strjoin(past, cmd);
	free(past);
	return (new);
}

int	call_execve(char **cmd, t_cmd *info)
{
	int	i;
	char	*path_cmd;

	path_cmd = ft_getenv("PATH", info->envp);
	path_cmd = ft_strjoin(path_cmd, ":");
	if (path_cmd)
		info->path = ft_split(path_cmd, ':');
	else
		info->path[0] = NULL;
	if (!access(cmd[0], F_OK))
	{
		if (access(cmd[0], X_OK))
			execve_fail(PERMISSION_DENIED, 126);
		else
		{
			if (execve(cmd[0], cmd, info->envp))
				error_exit("execve fail");
		}
	}
	i = 0;
	while (info->path[i])
	{
		path_cmd = make_path_cmd(info->path[i], cmd[0]);
		if (access(path_cmd, F_OK))
		{
			i++;
			continue ;
		}
		if (access(path_cmd, X_OK))
			execve_fail(PERMISSION_DENIED, 126);
		break ;
	}
	if (!info->path[i])
		execve_fail(CMD_NOT_FOUND, 127);
	free(cmd[0]);
	cmd[0] = path_cmd;
	if (execve(path_cmd, cmd, info->envp))
		error_exit("execve fail");
}
