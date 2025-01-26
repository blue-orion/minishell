/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:35:02 by takwak            #+#    #+#             */
/*   Updated: 2025/01/27 02:28:20 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tree.h"
#include <stdlib.h>
#include <stdio.h>

t_node	*new_node(t_list *list)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (perror("failed make node"), NULL);
	new->head = list;
	if (!list)
		new->head_data = NULL;
	else
		new->head_data = (t_data *)list->content;
	new->left_child = NULL;
	new->right_child = NULL;
	return (new);
}
