/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sentense.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:55:13 by takwak            #+#    #+#             */
/*   Updated: 2025/01/21 02:40:09 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_node	*parse_sentense(t_node **root)
{
	t_node	*cur;
	t_node	*past;
	int		separator;

	cur = *root;
	while (cur)
	{
		if (cur->data->type != SENTENSE)
		{
			past = cur;
			cur = cur->next;
			continue ;
		}
		separator = find_separator(data->text);
		if (separator)
		{
			make_tree_node(head, past, cur, separator);
		}

	}
	//SEPARATOR를 기준으로 CMD 구분
	//이후 SEPARAOTR 처리
}
