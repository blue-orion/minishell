/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:55:08 by takwak            #+#    #+#             */
/*   Updated: 2025/02/05 18:23:42 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	parse_node(t_node *parent, t_list *head, t_list *cur, int separator)
{
	t_data	*data;
	int		idx[2];

	data = (t_data *)cur->content;
	idx[LEFT] = which_separator(data->text, separator);
	idx[RIGHT] = idx[LEFT] + 1;
	if (separator == AND || separator == OR)
		idx[RIGHT]++;
	if (head == cur)
	{
		head_list_left_node(parent, cur, idx[LEFT]);
		head_list_right_node(parent, cur, idx[RIGHT]);
	}
	else
	{
		no_head_left_node(parent, head, cur, idx[LEFT]);
		no_head_right_node(parent, cur, idx[RIGHT]);
	}
	separator_node(parent, cur, separator, idx);
}
