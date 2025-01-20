/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sentense.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:55:13 by takwak            #+#    #+#             */
/*   Updated: 2025/01/17 22:58:13 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_node	*parse_sentense(t_node **root, t_list **head)
{
	t_data	*data;
	t_list	*cur;
	int		separator;

	cur = *head;
	while (cur)
	{
		data = (t_data *)cur->content;
		if (data->type != SENTENSE || data->type == PARENTHESIS)
		{
			cur = cur->next;
			continue ;
		}
		separator = find_separator(data->text);
		if (separator)
		{
			make_tree_node(root, separator, );
		}

	}
	//SEPARATOR를 기준으로 CMD 구분
	//이후 SEPARAOTR 처리
}
