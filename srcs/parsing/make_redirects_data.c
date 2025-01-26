/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_redirects_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:32:21 by takwak            #+#    #+#             */
/*   Updated: 2025/01/27 03:41:16 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	add_redirect_list(t_list **head, char *data, int *i, int redirect)
{
	int	start;
	int	end;
	t_data	*new_data;
	t_list	*new_lst;

	start = *i;
	if (redirect == IN || redirect == OUT)
		*i += 1;
	if (redirect == HERE_DOC || redirect == APPEND)
		*i += 2;
	*i += skip_space(data + *i);
	while (data[*i] && data[*i] != ' ' && !is_redirection(data + *i))
		(*i)++;
	end = *i;
	new_data = make_data(data, REDIRECTS, start, end);
	if (!new_data)
			return (-1);
	if (make_list_and_addback(head, new_data))
		return (-1);
	if (start != end && !data[*i])
		return (1);
	return (0);
}

int	extract_redirection(t_list **head, t_list *cmd_lst)
{
	int		i;
	int		redirect;
	int		status;
	t_data	*data;

	data = (t_data *)cmd_lst->content;
	i = 0;
	while (data->text[i])
	{
		redirect = is_redirection(data->text + i);
		if (redirect)
		{
			status = add_redirect_list(head, data->text, &i, redirect);
			if (status > 0)
				ft_lstadd_back(head, cmd_lst->next);
			if (status < 0)
				return (-1);
		}
		else
			i++;
	}
	return (0);
}

t_list	*make_redirects_list(t_list *head)
{
	t_list	*cur_lst;
	t_list	*res_lst;
	t_data	*data;

	res_lst = NULL;
	cur_lst = head;
	while (find_redirection(cur_lst))
	{
		cur_lst = move_to_token(cur_lst, CMD);
		data = (t_data *)cur_lst->content;
		if (extract_redirection(&res_lst, cur_lst))
		{
			ft_lstclear(&res_lst, free_data);
			return (NULL);
		}
		cur_lst = cur_lst->next;
	}
	return (res_lst);
}
