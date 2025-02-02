/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 04:18:48 by takwak            #+#    #+#             */
/*   Updated: 2025/02/02 20:30:32 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_node	*parsing(char *str)
{
	t_node	*root;
	t_list	*head;

	root = new_node(NULL);
	if (!root)
		perror("parsing failed");
	root = split_sentense_to_list(root, str);
	print_tree(root);
	printf("\n\n");
	if (!root->head)
		return (treeclear(root), NULL);
	if (make_parsing_tree(root))
		return (treeclear(root), NULL);
	if (split_cmd_node(root))
		return (treeclear(root), NULL);
	if (split_redirects_node(root))
		return (treeclear(root), NULL);
	return (root);
}
