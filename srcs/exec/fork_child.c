/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:52:33 by takwak            #+#    #+#             */
/*   Updated: 2025/03/21 19:43:11 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	fork_child(t_cmd *info, t_node *child_node)
{
	pid_t	child_pid;

	if (is_builtin_node(child_node))
		command_execve_process(info, child_node);
	else
	{
		child_pid = fork();
		if (child_pid < 0)
			error_exit("fork error");
		if (child_pid == 0)
			exec_tree_node(info, child_node);
		if (child_pid > 0)
			wait_child(info, child_pid);
	}
}
