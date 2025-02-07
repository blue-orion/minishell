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

int	separator_process(t_cmd *info, t_node *cur_node)
{
	t_data	*data;

	if (!cur_node)
		return (0);
	data = (t_data *)cur_node->head->content;
	if (data->type == PIPE)
		pipe_separator_process();
	if (data->type == AND || data->type == OR)
		logical_separator_process();
	if (data->type == SEMI || data->type == AMPER)
		simple_separator_process();
	return (0);
}
