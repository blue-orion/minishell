/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_new_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:35:02 by takwak            #+#    #+#             */
/*   Updated: 2025/01/21 02:37:49 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tree.h"
#include <stdlib.h>
#include <stdio.h>

t_node	*make_new_node(t_data *content, t_list *next)
{
	t_node	*new;

	if (!next)
		return (NULL);
	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (perror("failed make node"), NULL);
	new->data = content;
	new->next = next;
	new->left_child = NULL;
	new->right_child = NULL;
	return (new);
}
