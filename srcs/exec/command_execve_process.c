/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execve_process.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:42:37 by takwak            #+#    #+#             */
/*   Updated: 2025/03/11 20:10:06 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

int	command_execve_process(t_cmd *info, t_node *cur_node)
{
	t_data	*data;
	int		status;

	status = 0;
	if (!cur_node->head)
	{
		redirection_process(info, cur_node->left_child, &status);
		if (status)
		{
			g_exit_status = status;
			return (g_exit_status);
		}
		g_exit_status = exec_command(info, cur_node->right_child);
	}
	else
		g_exit_status = exec_command(info, cur_node);
	return (g_exit_status);
}
