/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execve_process.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:42:37 by takwak            #+#    #+#             */
/*   Updated: 2025/02/28 16:04:19 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

int	command_execve_process(t_cmd *info, t_node *cur_node)
{
	t_data	*data;
	int		status;

	info->exit_status = 0;
	if (!cur_node->head)
	{
		redirection_process(info, cur_node->left_child);
		if (info->exit_status)
			return (info->exit_status);
		info->exit_status = exec_command(info, cur_node->right_child);
	}
	else
		info->exit_status = exec_command(info, cur_node);
	return (info->exit_status);
}
