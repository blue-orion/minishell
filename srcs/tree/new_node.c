/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:35:02 by takwak            #+#    #+#             */
/*   Updated: 2025/02/02 20:30:09 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tree.h"

t_node	*new_node(t_list *list)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->head = list;
	if (!list)
		new->head_data = NULL;
	else
		new->head_data = (t_data *)list->content;
	new->left_child = NULL;
	new->right_child = NULL;
	return (new);
}
