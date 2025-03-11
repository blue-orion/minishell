/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execve_process.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:42:37 by takwak            #+#    #+#             */
/*   Updated: 2025/03/08 23:15:03 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

int	command_execve_process(t_cmd *info, t_node *cur_node)
{
	t_data	*data;
	int		status;

	status = 0;
	signal(SIGQUIT, SIG_DFL);
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
	signal(SIGQUIT, SIG_IGN);
	return (g_exit_status);
}
