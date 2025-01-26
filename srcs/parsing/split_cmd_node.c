/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeonsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:39:38 by takwak            #+#    #+#             */
/*   Updated: 2025/01/27 03:30:07 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	split_cmd_node(t_node *parent)
{
	t_list	*redirects_list;
	t_list	*simple_cmd_list;
	t_list	*cur_lst;

	if (!parent)
		return (0);
	if (!find_token(parent->head, CMD))
	{
		split_cmd_node(parent->left_child);
		split_cmd_node(parent->right_child);
		return (0);
	}
	redirects_list = make_redirects_list(parent->head);
	if (!redirects_list)
	{
		if (find_redirection(parent->head))
			return (-1);
		((t_data *)parent->head->content)->type = SIMPLE_CMD;
		return (0);
	}
	simple_cmd_list = make_simple_cmd_list(parent->head);
	if (!simple_cmd_list)
		return (-1);
	parent->left_child = new_node(redirects_list);
	if (!parent->left_child)
		return (-1);
	parent->right_child = new_node(simple_cmd_list);
	if (!parent->right_child)
		return (-1);
	parent->head = NULL;
	return (0);
}

