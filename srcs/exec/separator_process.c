/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separator_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:23:18 by takwak            #+#    #+#             */
/*   Updated: 2025/02/07 17:23:18 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	separator_process(t_cmd *info, t_node *cur_node)
{
	t_data	*data;

	if (!cur_node)
		return ;
	data = (t_data *)cur_node->head->content;
	info->parent = cur_node;
	if (data->type == PIPE)
		pipe_separator_process(info, cur_node);
	if (data->type == AND || data->type == OR)
	{
		fork_child(info, cur_node->left_child);
		if ((data->type == AND && info->exit_status != 0)
			|| (data->type == OR && info->exit_status == 0))
			return ;
		fork_child(info, cur_node->right_child);
	}
	if (data->type == SEMI || data->type == AMPER)
	{
		fork_child(info, cur_node->left_child);
		fork_child(info, cur_node->right_child);
	}
}

void	pipe_separator_process(t_cmd *info, t_node *cur_node)
{
	if (pipe(info->pipe_fd))
		error_exit("pipe error");
	info->pipe_flag = 1;
	info->pid[LEFT] = fork();
	if (info->pid[LEFT] < 0)
		error_exit("fork error");
	if (info->pid[LEFT] == 0)
	{
		exec_tree_node(info, cur_node->left_child);
		return ;
	}
	info->pid[RIGHT] = fork();
	if (info->pid[RIGHT] < 0)
		error_exit("fork error");
	if (info->pid[RIGHT] == 0)
	{
		exec_tree_node(info, cur_node->right_child);
		return ;
	}
	close(info->pipe_fd[INPUT]);
	close(info->pipe_fd[OUTPUT]);
	wait_child(info, info->pid[LEFT]);
	wait_child(info, info->pid[RIGHT]);
}
