/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:52:14 by takwak            #+#    #+#             */
/*   Updated: 2025/02/05 16:45:03 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tree.h"
#include "../../includes/utils.h"

void	print_tree(t_node *root)
{
	t_node	*cur_node;

	cur_node = root;
	if (!root)
		return ;
	printf("\n==============node adr : %p==================\n", root);
	print_type_a(root->type);
	print_type_b(root->type);
	printf("left child : %p     , ", root->left_child);
	printf("right child : %p\n", root->right_child);
	printf("====================================================\n");
	print_list(cur_node->head);
	print_tree(root->left_child);
	print_tree(root->right_child);
}
