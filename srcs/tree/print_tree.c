/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:52:14 by takwak            #+#    #+#             */
/*   Updated: 2025/01/21 23:23:43 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tree.h"
#include "../../includes/utils.h"

void	print_tree(t_node *root)
{
	t_node *cur_node;

	cur_node = root;
	if (!root)
		return ;
	print_tree(root->left_child);
	print_list(cur_node->head);
	print_tree(root->right_child);
}
