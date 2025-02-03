/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_redirects_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:55:19 by takwak            #+#    #+#             */
/*   Updated: 2025/02/03 17:36:08 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	split_redirects_node(t_node *parent)
{
	t_list	*new_lst;

	if (!parent)
		return ;
	if (!find_token(parent->head, REDIRECTS))
	{
		split_redirects_node(parent->left_child);
		split_redirects_node(parent->right_child);
		return ;
	}
	new_lst = make_redirection_list(&parent->head);
	parent->left_child = new_node(new_lst);
	if (!parent->left_child)
		error_exit("failed malloc in split_redirects_node");
	parent->right_child = new_node(parent->head->next);
	if (!parent->right_child)
		error_exit("failed malloc in split_redirects_node");
	parent->head->next = NULL;
	split_redirects_node(parent->left_child);
	split_redirects_node(parent->right_child);
	ft_lstclear(&parent->head, free_data);
}
