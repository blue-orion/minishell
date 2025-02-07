/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:05:40 by takwak            #+#    #+#             */
/*   Updated: 2025/02/07 22:05:40 by takwak           ###   ########.fr       */
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

int	call_execve(char **cmd, char **path)
{
	int	i;
	char	*path_cmd;

	if (!access(cmd[0], F_OK))
	{
		if (access(cmd[0], X_OK))
			execve_fail("Permission denied", 126);
		else
		{
			if (execve(path_cmd, cmd, NULL))
				error_exit("execve fail");
		}
	}
	i = 0;
	while (path[i])
	{
		path_cmd = make_path_cmd(path[i], cmd[0]);
		if (access(path_cmd, F_OK))
		{
			i++;
			continue ;
		}
		if (access(path_cmd, X_OK))
			execve_fail("Permission denied", 126);
		break ;
	}
	if (!path[i])
		execve_fail("command not found", 127);
	free(cmd[0]);
	cmd[0] = path_cmd;
	if (execve(path_cmd, cmd, NULL))
		error_exit("execve fail");
}
