/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthesis_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:24:57 by takwak            #+#    #+#             */
/*   Updated: 2025/02/26 15:36:21 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

int	parenthesis_process(t_cmd *info, t_node *cur_node)
{
	pid_t	child_pid;

	info->parent = cur_node;
	child_pid = fork();
	if (child_pid < 0)
		error_exit("fork failed");
	if (child_pid == 0)
		exec_tree_node(info, cur_node->left_child);
	if (child_pid > 0)
		wait_child(info, child_pid);
	return (0);
}
