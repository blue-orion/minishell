/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_parsing_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:14:59 by takwak            #+#    #+#             */
/*   Updated: 2025/02/06 21:52:35 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	exec_tree_node(t_cmd *info, t_node *cur_node)
{
	int	left_status;
	int	right_status;

	if (info->pipe_flag)
		redirect_pipe(info, cur_node);
	if (cur_node->type == PARENTHESIS)
	{
		parenthesis_process(info, cur_node);
	}
	if (cur_node->type == SEPARATOR)
	{
		separator_process(info, cur_node);
	}
	else
	{

	}
}
