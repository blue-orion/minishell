/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_separator_process.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:39:14 by takwak            #+#    #+#             */
/*   Updated: 2025/02/13 18:33:14 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	simple_separator_process(t_cmd *info, t_node *cur_node)
{
	t_data	*data;

	data = cur_node->head->content;
	if (is_builtin_node(info, cur_node->left_child))
		info->exit_status = command_execve_process(info, cur_node->left_child);
	else
	{
		info->pid[LEFT] = fork();
		if (info->pid[LEFT] < 0)
			error_exit("fork error");
		if (info->pid[LEFT] == 0)
		{
			exec_tree_node(info, cur_node->left_child);
			return ;
		}
		if (info->pid[LEFT] > 0)
			wait_child(info, info->pid[LEFT]);
	}
	if (is_builtin_node(info, cur_node->right_child))
		info->exit_status = exec_command(info, cur_node->right_child);
	else
	{
		info->pid[RIGHT] = fork();
		if (info->pid[RIGHT] < 0)
			error_exit("fork error");
		if (info->pid[RIGHT] == 0)
		{
			exec_tree_node(info, cur_node->right_child);
			return ;
		}
		if (info->pid[RIGHT] > 0)
			wait_child(info, info->pid[LEFT]);
	}
}
