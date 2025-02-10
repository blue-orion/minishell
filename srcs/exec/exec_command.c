/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:52:44 by takwak            #+#    #+#             */
/*   Updated: 2025/02/09 21:22:51 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

int	exec_command(t_cmd *info, t_node *cur_node)
{
	info->cmd = list_to_str(cur_node->head);
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
			{
				waitpid(info->pid[0], &info->exit_status, 0);
				printf("pid : %d, exit_status = %d\n", info->pid[0], info->exit_status);
			}
		}
		else
			call_execve(info->cmd, info);
	}
	return (info->exit_status);
}
