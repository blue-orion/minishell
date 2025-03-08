/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 04:18:48 by takwak            #+#    #+#             */
/*   Updated: 2025/03/07 20:56:11 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_node	*parsing(char *str)
{
	t_node	*root;
	t_list	*head;
	char	*input;

	input = preprocess_string(str);
	root = new_node(NULL);
	if (!root)
		error_exit("failed malloc in parsing");
	root = split_sentense_to_list(root, input);
	if (!root || !root->head)
		return (treeclear(root), NULL);
	make_parsing_tree(root);
	split_cmd_node(root);
	split_redirects_node(root);
	return (root);
}
