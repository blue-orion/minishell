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
	new->type = 0;
	if (list)
		new->type = ((t_data *)list->content)->type;
	new->left_child = NULL;
	new->right_child = NULL;
	return (new);
}
