/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:09:12 by takwak            #+#    #+#             */
/*   Updated: 2025/01/20 21:09:12 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_node	*make_tree_node(t_node **root, t_list **head, int separator, t_list *lst)
{
	t_node	*new;
	t_data	*data;
	t_data	*new_data;
	int		left;
	int		right;

	data = (t_data *)lst->content;
	left = which_separator(data->text, separator);
	if (separator == AND || separator == OR)
		right = left + 5;
	else
		right = left + 4;
	new_data = make_data(data->text, SEPARATOR, left, right);
	new = make_new_node(separator, (void *)new_data);
	if (*head == lst)
	{
		new_data = make_data(data->text, CMD, 0, left);
		new->left_child = make_new_node(CMD, (void *)new_data);
	}
	return (new);
}
