/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:05:40 by takwak            #+#    #+#             */
/*   Updated: 2025/03/11 21:17:04 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"
#include <sys/stat.h>

char	*make_path_cmd(char *path, char *cmd);
char	**get_path_array(t_cmd *info);
int		is_executable_path(char *cmd, t_cmd *info);
char	*get_executable_path(char **cmd, t_cmd *info);

void	call_execve(char **cmd, t_cmd *info)
{
	char	*path_cmd;

	signal(SIGQUIT, SIG_DFL);
	if (is_executable_path(cmd[0], info))
	{
		if (execve(cmd[0], cmd, info->envp))
			error_exit("execve fail");
	}
	path_cmd = get_executable_path(cmd, info);
	if (!path_cmd)
		execve_fail(info, cmd[0], CMD_NOT_FOUND, 127);
	free(cmd[0]);
	cmd[0] = path_cmd;
	if (execve(path_cmd, cmd, info->envp))
		error_exit("execve fail");
}

char	*make_path_cmd(char *path, char *cmd)
{
	char	*new;
	char	*past;

	past = ft_strjoin(path, "/");
	new = ft_strjoin(past, cmd);
	free(past);
	return (new);
}

char	**get_path_array(t_cmd *info)
{
	char	*path_env;
	char	**path;

	path_env = ft_getenv("PATH", info->envp);
	if (path_env)
		path = ft_split(path_env, ':');
	else
		path = NULL;
	return (path);
}

int	is_executable_path(char *cmd, t_cmd *info)
{
	struct stat	statbuf;

	if (access(cmd, F_OK))
		return (0);
	stat(cmd, &statbuf);
	if (S_ISDIR(statbuf.st_mode))
		execve_fail(info, cmd, IS_DIR, 126);
	if (access(cmd, X_OK))
		execve_fail(info, cmd, PERMISSION_DENIED, 126);
	return (1);
}

char	*get_executable_path(char **cmd, t_cmd *info)
{
	int		i;
	char	**path;
	char	*path_cmd;

	path = get_path_array(info);
	i = 0;
	while (path[i])
	{
		path_cmd = make_path_cmd(path[i], cmd[0]);
		if (is_executable_path(path_cmd, info))
			return (path_cmd);
		free(path_cmd);
		i++;
	}
	free_pptr((void **)path);
	return (NULL);
}
