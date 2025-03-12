/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tree_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:14:59 by takwak            #+#    #+#             */
/*   Updated: 2025/03/12 16:42:58 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	exec_tree_node(t_cmd *info, t_node *cur_node)
{
	if (info->pipe_flag)
	{
		redirect_pipe(info, cur_node);
		info->pipe_flag = 0;
	}
	if (cur_node->type != PARENTHESIS && cur_node->type != SEPARATOR)
		command_execve_process(info, cur_node);
	if (cur_node->type == PARENTHESIS)
		parenthesis_process(info, cur_node);
	if (cur_node->type == SEPARATOR)
		separator_process(info, cur_node);
	if (info->root != cur_node)
	{
		end_process(info);
		exit(g_exit_status);
	}
}
