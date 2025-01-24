/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:37:45 by takwak            #+#    #+#             */
/*   Updated: 2025/01/24 18:12:49 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	parsing(char *str)
{
	t_node	*root;
	t_list	*head;

	root = new_node(NULL);
	if (!root)
		return (-1);
	root = split_sentense_to_list(root, str);
	if (!root)
		return (-1);
	print_list(root->head);
	printf("\n\n");
	if (make_parsing_tree(root))
		return (-1);
	if (split_cmd_node(root))
		return (-1);
	// if (split_redirects_node(root))
	// 	return (-1);
	print_tree(root);
	return (0);
}
