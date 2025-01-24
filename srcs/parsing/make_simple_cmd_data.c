/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_simple_cmd_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeonsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:38:29 by takwak            #+#    #+#             */
/*   Updated: 2025/01/24 20:38:11 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	extract_simple_cmd(t_list **dst_head, t_list *cmd_lst, t_list *src_head)
{
	int	i;
	int	redirect;
	int	status;
	int	start;
	int	end;
	t_data	*new_data;
	t_list	*past_lst;
	t_data	*data;

	i = 0;
	start = 0;
	data = (t_data *)cmd_lst->content;
	while (data->text[i])
	{
		redirect = is_redirection(data->text + i);
		if (redirect)
		{
			end = i;
			new_data = make_data(data->text, SIMPLE_CMD, start, end);
			if (!new_data)
				return (-1);
			if (new_data->type == EMPTY)
			{
				past_lst = src_head;
				while (past_lst->next != cmd_lst)
					past_lst = past_lst->next;
				past_lst->next = NULL;
				*dst_head = src_head;
			}
			else
				if (make_list_and_addback(dst_head, new_data))
					return (-1);
			if (redirect == IN || redirect == OUT)
				i += 1;
			if (redirect == HERE_DOC || redirect == APPEND)
				i += 2;
			i += skip_space(data->text + i);
			while (data->text[i] && data->text[i] != ' ' && !is_redirection(data->text + i))
				i++;
			start = i;
		}
		else
			i++;
	}
	return (0);
}

t_list	*make_simple_cmd_list(t_list *head)
{
	t_list	*cur_lst;
	t_list	*res_lst;
	t_data	*data;

	res_lst = NULL;
	cur_lst = head;
	while (find_redirection(cur_lst))
	{
		cur_lst = move_to_token(cur_lst, CMD);
		if (extract_simple_cmd(&res_lst, cur_lst, head))
			return (NULL);
		cur_lst = cur_lst->next;
	}
	return (res_lst);
}
