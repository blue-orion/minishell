/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:41:23 by takwak            #+#    #+#             */
/*   Updated: 2025/01/17 22:46:40 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	add_node_left(t_node *parent, t_node *child)
{
	if (!child)
		return (-1);
	parent->left_child = child;
	return (0);
}

int	add_node_right(t_node *parent, t_node *child)
{
	if (!child)
		return (-1);
	parent->left_child = child;
	return (0);
}
