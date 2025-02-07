/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:28:30 by takwak            #+#    #+#             */
/*   Updated: 2025/02/07 18:28:30 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	redirect_pipe(t_cmd *info, t_node *cur_node)
{
	if (cur_node == info->parent->left_child)
		dup2(info->pipe_fd[INPUT], 1);
	if (cur_node == info->parent->right_child)
		dup2(info->pipe_fd[OUTPUT], 0);
	close(info->pipe_fd[0]);
	close(info->pipe_fd[1]);
	info->pipe_flag = 0;
}
