/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeonsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:38:29 by takwak            #+#    #+#             */
/*   Updated: 2025/01/23 23:54:34 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_list	*make_simple_cmd_list(t_node *parent)
{
	t_list	*cur_lst;
	t_node	*cur_node;
	t_data	*data;

	cur_lst = move_to_token(parent->head, CMD);
	data = (t_data *)cur_lst->content;
	cur_lst = find_redirection(cur_lst);
	if (cur_lst != cur_node->head)
	{
	}
	if (!find_redirection(cur_lst))
		;
}
