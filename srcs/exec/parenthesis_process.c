/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthesis_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:24:57 by takwak            #+#    #+#             */
/*   Updated: 2025/02/15 17:57:08 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

int	parenthesis_process(t_cmd *info, t_node *cur_node)
{
	info->pid[LEFT] = fork();
	info->parent = cur_node;
	if (info->pid[LEFT] < 0)
		return (-1);
	if (info->pid[LEFT] == 0)
		exec_tree_node(info, cur_node->left_child);
	if (info->pid[LEFT] > 0)
	{
		waitpid(info->pid[LEFT], &info->exit_status, 0);
		// printf("parenthesis pid : %d, exit_status = %d\n", info->pid[LEFT], info->exit_status);
	}
	return (0);
}
