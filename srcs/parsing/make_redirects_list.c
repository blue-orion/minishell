/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_redirects_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:32:21 by takwak            #+#    #+#             */
/*   Updated: 2025/02/25 22:18:52 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	add_redirect_list(t_list **head, char *data, int *i, int redirect);
int	extract_redirection(t_list **head, t_list *cmd_lst);

t_list	*make_redirects_list(t_list *head)
{
	t_list	*cur_lst;
	t_list	*res_lst;

	res_lst = NULL;
	cur_lst = head;
	while (find_redirection(cur_lst))
	{
		cur_lst = move_to_token(cur_lst, CMD);
		extract_redirection(&res_lst, cur_lst);
		cur_lst = cur_lst->next;
	}
	return (res_lst);
}

int	add_redirect_list(t_list **head, char *data, int *i, int redirect)
{
	int		start;
	int		end;
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
		error_exit("failed malloc in split_cmd_node");
	make_list_and_addback(head, new_data);
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
		}
		else
			i++;
	}
	return (0);
}
