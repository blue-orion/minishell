/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:12:17 by takwak            #+#    #+#             */
/*   Updated: 2025/01/23 15:18:10 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	split_cmd_node(t_node *cur_node)
{
	t_data	*data;
	t_data	*redirect_data;
	t_data	*cmd_data;
	t_data	*file_data;
	t_list	*cur_list;

	if (!find_token(cur_node->head, CMD))
	{
		split_cmd_node(cur_node->left_child);
		split_cmd_node(cur_node->right_child);
		return (0);
	}
	print_list(cur_node->head);
	cur_list = move_to_token(cur_node->head, CMD);
	data = (t_data *)cur_list->content;
	cur_list = find_redirection(cur_list);
	if (cur_list != cur_node->head)
	{
	}
	if (!find_redirection(data))
}

