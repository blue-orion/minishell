/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 04:18:48 by takwak            #+#    #+#             */
/*   Updated: 2025/02/01 19:40:58 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_node	*parsing(char *str)
{
	t_node	*root;
	t_list	*head;

	root = new_node(NULL);
	if (!root)
		return (treeclear(root), NULL);
	root = split_sentense_to_list(root, str);
	if (!root || !root->head)
		return (treeclear(root), NULL);
	print_list(root->head);
	printf("\n\n");
	if (make_parsing_tree(root))
		return (treeclear(root), NULL);
	if (split_cmd_node(root))
		return (treeclear(root), NULL);
	if (split_redirects_node(root))
		return (treeclear(root), NULL);
	return (root);
}
