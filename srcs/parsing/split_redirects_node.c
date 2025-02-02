/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_redirects_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:55:19 by takwak            #+#    #+#             */
/*   Updated: 2025/02/02 16:19:34 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	split_redirects_node(t_node *parent)
{
	t_list	*new_lst;
	t_node	*left_node;
	t_node	*right_node;

	if (!parent)
		return (0);
	if (!find_token(parent->head, REDIRECTS))
	{
		split_redirects_node(parent->left_child);
		split_redirects_node(parent->right_child);
		return (0);
	}
	new_lst = make_redirection_list(parent->head);
	if (!new_lst)
		return (perror("make redirection list failed"), -1);
	left_node = new_node(new_lst);
	if (!left_node)
		return (perror("make new_node failed"), -1);
	parent->left_child = left_node;
	right_node = new_node(parent->head->next);
	if (!right_node)
		return (perror("make new_node failed"), -1);
	parent->right_child = right_node;
	parent->head->next = NULL;
	split_redirects_node(parent->left_child);
	split_redirects_node(parent->right_child);
	parent->head = NULL;
	return (0);
}
