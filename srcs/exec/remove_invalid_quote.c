/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_invalid_quote.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:41:41 by takwak            #+#    #+#             */
/*   Updated: 2025/02/27 19:41:41 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	join_next_piece(t_list *cur_lst)
{
	t_list	*next_lst;
	t_data	*next_data;
	t_data	*cur_data;

	cur_data = (t_data *)cur_lst->content;
	next_lst = cur_lst->next;
	next_data = (t_data *)cur_lst->next->content;
	cur_data->text = ft_join_free(cur_data->text, next_data->text);
	cur_lst->next = cur_lst->next->next;
	ft_lstdelone(next_lst, free_data);
}

void	join_past_piece(t_list *past_lst, t_list *cur_lst)
{
	t_data	*past_data;
	t_data	*cur_data;

	past_data = (t_data *)past_lst->content;
	cur_data = (t_data *)cur_lst->content;
	past_data->text = ft_join_free(past_data->text, cur_data->text);
	past_lst->next = cur_lst->next;
	ft_lstdelone(cur_lst, free_data);
}

void	remove_invalid_quote(t_list *head)
{
	t_list	*past_lst;
	t_list	*cur_lst;
	t_data	*cur_data;

	cur_lst = head;
	past_lst = NULL;
	while (cur_lst)
	{
		cur_data = (t_data *)cur_lst->content;
		if (cur_data->invalid[1])
			join_next_piece(cur_lst);
		if (cur_data->invalid[0])
		{
			join_past_piece(past_lst, cur_lst);
			cur_lst = past_lst;
		}
		past_lst = cur_lst;
		cur_lst = cur_lst->next;
	}
}
