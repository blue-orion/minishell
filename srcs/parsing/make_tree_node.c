/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:09:12 by takwak            #+#    #+#             */
/*   Updated: 2025/01/21 02:31:36 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_node	*make_tree_node(t_list **head, t_list *past, t_list *cur, int separator)
{
	t_node	*new;
	t_data	*data;
	t_data	*new_data;
	int		left;
	int		right;
	char	*past_str;
	t_list	*past_lst;

	data = (t_data *)cur->content;
	left = which_separator(data->text, separator);
	if (separator == AND || separator == OR)
		right = left + 5;
	else
		right = left + 4;
	new_data = make_data(data->text, SEPARATOR, left, right);
	new = make_new_node(ft_lstnew((void *)new_data));
	if (*head == cur)
	{
		new_data = make_data(data->text, CMD, 0, left);
		new->left_child = make_new_node(ft_lstnew((void *)new_data));
		past_str = data->text;
		data->text = ft_strdup(data->text + right);
		free(past_str);
		data->start += right;
		new->right_child = make_new_node(cur);
	}
	else
	{
		if (left == data->start && right == data->end)
		{
			new->left_child = make_new_node(past);
			new->right_child = make_new_node(cur->next);
		}
	}
	return (new);
}
