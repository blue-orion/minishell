/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:09:12 by takwak            #+#    #+#             */
/*   Updated: 2025/01/22 02:32:59 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	parse_node(t_node *cur_node, t_list *past, t_list *cur, int separator)
{
	t_data	*data;
	t_data	*new_data;
	int		left;
	int		right;
	char	*past_str;
	t_list	*past_lst;
	t_list	*new_lst;

	data = (t_data *)cur->content;
	left = which_separator(data->text, separator);
	if (separator == AND || separator == OR)
		right = left + 2;
	else
		right = left + 1;
	if (past == cur)
	{
		new_data = make_data(data->text, CMD, 0, left);
		if (!new_data)
			return (-1);
		if (new_data->type != EMPTY)
		{
			new_lst = ft_lstnew((void *)new_data);
			if (!new_lst)
			{
				free(new_data);
				return (-1);
			}
			cur_node->left_child = make_new_node(new_lst);
			if (!cur_node->left_child)
			{
				ft_lstclear(&new_lst, free);
				return (-1);
			}
		}
		else
			free(new_data);
		new_data = make_data(data->text, SENTENSE, right, data->end);
		if (new_data->type != EMPTY)
		{
			new_lst = ft_lstnew((void *)new_data);
			new_lst->next = cur->next;
			cur_node->right_child = make_new_node(new_lst);
		}
		else
		{
			free(new_data);
			cur_node->right_child = make_new_node(cur->next);
		}
	}
	else
	{
		past_lst = past;
		while (past_lst->next != cur)
			past_lst = past_lst->next;
		past_lst->next = NULL;
		new_data = make_data(data->text, CMD, 0, left);
		new_lst = ft_lstnew((void *)new_data);
		if (new_data->type != EMPTY)
			past_lst->next = new_lst;
		else
			;
			//have to free new_data, new_lst
		cur_node->left_child = make_new_node(past);
		new_data = make_data(data->text, SENTENSE, right, data->end);
		if (new_data->type == EMPTY)
		{
			free(new_data);
			cur_node->right_child = make_new_node(cur->next);
		}
		else
		{
			new_lst = ft_lstnew((void *)new_data);
			new_lst->next = cur->next;
			cur_node->right_child = make_new_node(new_lst);
		}
	}
	past_lst = cur;
	new_data = make_data(data->text, SEPARATOR, left, right);
	cur_node->head = ft_lstnew((void *)new_data);
	free(data->text);
	free(data);
	free(cur);
	return (0);
}
