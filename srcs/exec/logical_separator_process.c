/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_separator_process.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:34:19 by takwak            #+#    #+#             */
/*   Updated: 2025/02/13 18:32:54 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	logical_separator_process(t_cmd *info, t_node *cur_node)
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
			exec_tree_node(info, cur_node->left_child);
		if (info->pid[LEFT] > 0)
			waitpid(info->pid[LEFT], &info->exit_status, 0);
	}
	printf("left pid : %d, exit_status = %d\n", info->pid[LEFT], info->exit_status);
	if ((data->type == AND && info->exit_status != 0)
		|| (data->type == OR && info->exit_status == 0))
		return ;
	if (is_builtin_node(info, cur_node->right_child))
		info->exit_status = command_execve_process(info, cur_node->right_child);
	else
	{
		info->pid[RIGHT] = fork();
		if (info->pid[RIGHT] < 0)
			error_exit("fork error");
		if (info->pid[RIGHT] == 0)
			exec_tree_node(info, cur_node->right_child);
		if (info->pid[RIGHT] > 0)
			waitpid(info->pid[RIGHT], &info->exit_status, 0);
	}
	printf("right pid : %d, exit_status = %d\n", info->pid[RIGHT], info->exit_status);
}
