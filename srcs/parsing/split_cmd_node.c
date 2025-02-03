/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeonsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:39:38 by takwak            #+#    #+#             */
/*   Updated: 2025/02/03 17:18:10 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	child_nodes(t_node *parent);

void	split_cmd_node(t_node *parent)
{
	t_list	*cur_lst;

	if (!parent)
		return ;
	if (!find_token(parent->head, CMD))
	{
		split_cmd_node(parent->left_child);
		split_cmd_node(parent->right_child);
		return ;
	}
	child_nodes(parent);
}

void	child_nodes(t_node *parent)
{
	t_list	*redirects_list;
	t_list	*simple_cmd_list;

	if (!find_redirection(parent->head))
		((t_data *)parent->head->content)->type = SIMPLE_CMD;
	else
	{
		redirects_list = make_redirects_list(parent->head);
		simple_cmd_list = make_simple_cmd_list(parent->head);
		parent->left_child = new_node(redirects_list);
		if (!parent->left_child)
			error_exit("failed malloc in split_cmd_node");
		parent->right_child = new_node(simple_cmd_list);
		if (!parent->right_child)
			error_exit("failed malloc in split_cmd_node");
		parent->head = NULL;
	}
}
