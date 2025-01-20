/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_new_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:35:02 by takwak            #+#    #+#             */
/*   Updated: 2025/01/18 16:22:28 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tree.h"
#include <stdlib.h>
#include <stdio.h>

t_node	*make_new_node(int type, void *content)
{
	t_node	*new;

	if (!content)
		return (NULL);
	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (perror("failed make node"), NULL);
	new->type = type;
	new->content = content;
	new->left_child = NULL;
	new->right_child = NULL;
	return (new);
}
