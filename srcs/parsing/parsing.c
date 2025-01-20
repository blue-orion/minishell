/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:32:46 by takwak            #+#    #+#             */
/*   Updated: 2025/01/21 02:38:28 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	parsing(char *str)
{
	t_node	*root;
	t_list	*head;

	head = sentense_preprocess(str);
	if (!head)
		return (-1);
	print_list(head);
	root = make_new_node((t_data *)head->content, head->next);
	root = parse_sentense(&root);
	// if (!root)
	// 	return (NULL);
}
