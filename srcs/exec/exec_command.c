/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:52:44 by takwak            #+#    #+#             */
/*   Updated: 2025/02/24 19:15:09 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

int	exec_command(t_cmd *info, t_node *cur_node)
{
	info->cmd = list_to_str(info, cur_node->head);
	if (!info->cmd)
		return (1);
	if (is_builtin_command(info->cmd[0]))
		info->exit_status = call_builtin_ft(info->cmd, info);
	else
	{
		if (!info->parent)
		{
			info->pid[0] = fork();
			if (info->pid[0] < 0)
				error_exit("fork error");
			if (info->pid[0] == 0)
				call_execve(info->cmd, info);
			if (info->pid[0] > 0)
				wait_child(info, info->pid[0]);
		}
		else
			call_execve(info->cmd, info);
	}
	free_pptr((void **)info->cmd);
	return (info->exit_status);
}
