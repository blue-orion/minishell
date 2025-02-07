/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_child_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:06:16 by takwak            #+#    #+#             */
/*   Updated: 2025/02/06 21:26:00 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

int	make_child_process(t_cmd *info)
{
	t_data	*data;

	data = (t_data *)info->root->head->content;
	if (data->type == PIPE)
		if (pipe(info->pipe_fd))
			return (-1);
	info->pid[LEFT] = fork();
	info->pid[RIGHT] = fork();
	if (info->pid[LEFT] == -1 || info->pid[RIGHT] == -1)
		return (-1);
	if (info->pid[LEFT] == 0)
		exec_tree_node(info, info->root->left_child);
	if (info->pid[RIGHT] == 0)
		exec_tree_node(info, info->root->right_child);
	return (0);
}
