/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_parsing_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:14:59 by takwak            #+#    #+#             */
/*   Updated: 2025/02/05 21:14:59 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_parsing_tree(t_cmd *info, t_node *parent)
{
	t_data	*cur_data;

	cur_data = (t_data *)parent->head->content;
	if (cur_data->type == SIMPLE_CMD)
	{
		info->cmd = list_to_str(parent->head);
		printf("%s\n", *info->cmd);
		echo(info->cmd);
	}
}
