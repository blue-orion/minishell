/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execve_process.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:42:37 by takwak            #+#    #+#             */
/*   Updated: 2025/02/07 22:42:37 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

int	command_execve_process(t_cmd *info, t_node *cur_node)
{
	t_data	*data;
	int		status;

	data = (t_data *)cur_node->head->content;
	if (data->type == SIMPLE_CMD)
	{
		status = exec_command(info, cur_node);
	}
	else
	{
		redirection_process(info, cur_node->left_child);
		status = exec_command(info, cur_node->right_child);
	}
	return (status);
}
