/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sentense.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:55:13 by takwak            #+#    #+#             */
/*   Updated: 2025/01/22 02:38:21 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	dont_have_sentense(t_list *lst)
{
	t_data	*data;
	t_list	*cur;

	cur = lst;
	while (cur)
	{
		data = (t_data *)cur->content;
		if (data->type == SENTENSE)
			return (0);
		cur = cur->next;
	}
	return (1);
}

t_node	*parse_sentense(t_node *cur_node)
{
	t_list	*cur_lst;
	t_list	*past_lst;
	t_data	*data;
	int		separator;

	if (!cur_node)
		return (NULL);
	past_lst = NULL;
	cur_lst = cur_node->head;
	data = (t_data *)cur_lst->content;
	if (dont_have_sentense(cur_lst))
	{
		if (data->type == PARENTHESIS)
		{
			cur_node = sentense_preprocess(cur_node, data->text);
			cur_node->head = cur_node->head->next;
			//have to free past list
			parse_sentense(cur_node);
			return (NULL);
		}
		return (NULL);
	}
	while (data->type != SENTENSE)
	{
		past_lst = cur_lst;
		cur_lst = cur_lst->next;
		data = (t_data *)cur_lst->content;
	}
	separator = find_separator(data->text);
	if (separator)
		parse_node(cur_node, cur_node->head, cur_lst, separator);
	else
	{
		data->type = CMD;
		if (!dont_have_sentense(cur_lst))
			parse_sentense(cur_node);
	}
	parse_sentense(cur_node->left_child);
	parse_sentense(cur_node->right_child);
}
