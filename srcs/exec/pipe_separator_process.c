/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_separator_process.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:42:35 by takwak            #+#    #+#             */
/*   Updated: 2025/02/15 17:57:04 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	pipe_separator_process(t_cmd *info, t_node *cur_node)
{
	int	pid;

	info->parent = cur_node;
	if (pipe(info->pipe_fd))
		error_exit("pipe error");
	info->pipe_flag = 1;
	pid = fork();
	if (pid < 0)
		error_exit("fork error");
	if (pid == 0)
	{
		exec_tree_node(info, cur_node->left_child);
		return ;
	}
	if (pid > 0)
		info->pid[LEFT] = pid;
	pid = fork();
	if (pid < 0)
		error_exit("fork error");
	if (pid == 0)
	{
		exec_tree_node(info, cur_node->right_child);
		return ;
	}
	if (pid > 0)
		info->pid[RIGHT] = pid;
	// printf("left pid : %d\n", info->pid[LEFT]);
	// printf("right pid : %d\n", info->pid[RIGHT]);
	close(info->pipe_fd[INPUT]);
	close(info->pipe_fd[OUTPUT]);
	waitpid(info->pid[LEFT], &info->exit_status, 0);
	// printf("left pid : %d, exit_status = %d\n", info->pid[LEFT], info->exit_status);
	waitpid(info->pid[RIGHT], &info->exit_status, 0);
	// printf("right pid : %d, exit_status = %d\n", info->pid[RIGHT], info->exit_status);
}
