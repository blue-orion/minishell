/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_parsing_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:55:13 by takwak            #+#    #+#             */
/*   Updated: 2025/02/02 21:29:05 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	parenthesis_list(t_node *parent, t_list *head)
{
	t_list	*past_lst;
	t_data	*data;

	data = (t_data *)head->content;
	past_lst = parent->head;
	parent = split_sentense_to_list(parent, data->text);
	parent->head = parent->head->next;
	ft_lstdelone(past_lst, free_data);
	make_parsing_tree(parent);
}

int	make_parsing_tree(t_node *cur_node)
{
	t_list	*cur_lst;
	t_data	*data;
	int		separator;

	if (!cur_node || !cur_node->head)
		return (0);
	while (find_token(cur_node->head, SENTENSE))
	{
		cur_lst = move_to_token(cur_node->head, SENTENSE);
		data = (t_data *)cur_lst->content;
		separator = find_separator(data->text);
		if (separator)
			parse_node(cur_node, cur_node->head, cur_lst, separator);
		else
			data->type = CMD;
		make_parsing_tree(cur_node->left_child);
		make_parsing_tree(cur_node->right_child);
	}
	if (is_type(PARENTHESIS, cur_node->head))
		parenthesis_list(cur_node, cur_node->head);
	return (0);
}
