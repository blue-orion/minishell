/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_redirects_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:32:21 by takwak            #+#    #+#             */
/*   Updated: 2025/01/24 01:16:25 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_list	*extract_redirection(t_list *cmd_lst)
{
	t_list	*cur;
	t_data	*data;
	int		i;

	cur = cmd_lst;
	data = (t_data *)cmd_lst->content;
	i = 0;
	while (data->text[i])
	{
		if (is_redirection(data->text + i))
		{
			while (data->text[i] == ' ')
				i++;

		}
	}
}
t_list	*make_redirects_list(t_node *parent)
{
	t_list	*cur_lst;
	t_list	*res_lst;
	t_list	*new_lst;
	t_data	*data;

	res_lst = NULL;
	cur_lst = move_to_token(parent->head, CMD);
	data = (t_data *)cur_lst->content;
	while (cur_lst)
	{
		new_lst = extract_redirection(cur_lst);
	}
}
