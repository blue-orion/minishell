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
	info->root = NULL;
	info->cmd = NULL;
	info->pid[0] = 0;
	info->pid[1] = 0;
	info->pipe_fd[0] = 0;
	info->pipe_fd[1] = 0;
	sigemptyset(&info->set);
	info->exit_status = 0;
}
