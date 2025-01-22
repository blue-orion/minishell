/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:32:46 by takwak            #+#    #+#             */
/*   Updated: 2025/01/21 23:03:15 by takwak           ###   ########.fr       */
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
	print_tree(root);
	return (0);
}
