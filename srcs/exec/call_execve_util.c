/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_execve_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:33:33 by takwak            #+#    #+#             */
/*   Updated: 2025/03/12 22:19:04 by takwak           ###   ########.fr       */
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

char	**get_path_array(t_cmd *info)
{
	char	*path_env;
	char	**path;

	path_env = ft_getenv("PATH", info->envp);
	if (!path_env)
		return (NULL);
	path = ft_split(path_env, ':');
	return (path);
}
