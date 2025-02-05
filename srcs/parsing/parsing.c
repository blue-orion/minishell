/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 04:18:48 by takwak            #+#    #+#             */
/*   Updated: 2025/02/05 18:24:15 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_node	*parsing(char *str)
{
	t_node	*root;
	t_list	*head;

	root = new_node(NULL);
	if (!root)
		error_exit("failed malloc in parsing");
	root = split_sentense_to_list(root, str);
	if (!root || !root->head)
		return (treeclear(root), NULL);
	make_parsing_tree(root);
	split_cmd_node(root);
	split_redirects_node(root);
	return (root);
}
