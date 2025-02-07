/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:48:15 by takwak            #+#    #+#             */
/*   Updated: 2025/02/07 17:48:15 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	init_info(t_cmd *info)
{
	char	*path_env;

	path_env = getenv("PATH");
	info->root = NULL;
	info->cmd = NULL;
	info->pid[0] = 0;
	info->pid[1] = 0;
	info->pipe_fd[INPUT] = 0;
	info->pipe_fd[OUTPUT] = 0;
	info->stdfd[INPUT] = dup(0);
	info->stdfd[OUTPUT] = dup(1);
	info->parent = NULL;
	info->path = ft_split(path_env, ':');
	sigemptyset(&info->set);
	info->exit_status = 0;
}
