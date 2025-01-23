/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_parsing_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:55:13 by takwak            #+#    #+#             */
/*   Updated: 2025/01/23 15:06:44 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	make_parsing_tree(t_node *cur_node)
{
	t_list	*cur_lst;
	t_list	*past_lst;
	t_data	*data;
	int		separator;

	if (!cur_node)
		return (0);
	cur_lst = cur_node->head;
	data = (t_data *)cur_lst->content;
	while (find_token(cur_node->head, SENTENSE))
	{
		cur_lst = move_to_token(cur_lst, SENTENSE);
		data = (t_data *)cur_lst->content;
		separator = find_separator(data->text);
		if (separator)
		{
			if (parse_node(cur_node, cur_node->head, cur_lst, separator))
				return (perror("failed making node"), -1);
		}
		else
			data->type = CMD;
		if (make_parsing_tree(cur_node->left_child))
			return (-1);
		if (make_parsing_tree(cur_node->right_child))
			return (-1);
	}
	if (data->type == PARENTHESIS)
	{
		cur_node = split_sentense_to_list(cur_node, data->text);
		if (!cur_node)
			return (-1);
		free(data->text);
		free(data);
		past_lst = cur_node->head;
		cur_node->head = cur_node->head->next;
		free(past_lst);
		if (make_parsing_tree(cur_node))
			return (-1);
	}
	return (0);
}
