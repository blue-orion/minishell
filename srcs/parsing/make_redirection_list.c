/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_redirection_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:48:08 by takwak            #+#    #+#             */
/*   Updated: 2025/02/03 17:34:12 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	redirection_list(t_list **head, t_data *data);
int		file_name_list(t_list **dst, t_list *src);

t_list	*make_redirection_list(t_list **head)
{
	t_data	*cur_data;
	t_list	*new_lst;

	new_lst = NULL;
	cur_data = (t_data *)(*head)->content;
	redirection_list(&new_lst, cur_data);
	if (file_name_list(&new_lst, *head))
		*head = (*head)->next;
	return (new_lst);
}

void	redirection_list(t_list **head, t_data *data)
{
	t_data	*new_data;
	int		redirection;
	int		start;
	int		end;

	start = which_redirection(data->text, &redirection);
	end = start + 1;
	if (redirection == HERE_DOC || redirection == APPEND)
		end++;
	new_data = make_data(data->text, redirection, start, end);
	if (!new_data)
		error_exit("failed malloc in make redirection list");
	if (make_list_and_addback(head, new_data))
		error_exit("failed malloc in make redirection list");
}

int	file_name_list(t_list **dst, t_list *src)
{
	t_data	*new_data;
	t_data	*cur_data;
	int		redirection;
	int		start;
	int		end;

	cur_data = (t_data *)src->content;
	start = which_redirection(cur_data->text, &redirection) + 1;
	if (redirection == HERE_DOC || redirection == APPEND)
		start++;
	end = ft_strlen(cur_data->text);
	new_data = make_data(cur_data->text, FILE_NAME, start, end);
	if (!new_data)
		error_exit("failed malloc in make redirection list");
	if (new_data->type == EMPTY)
	{
		free(new_data);
		ft_lstadd_back(dst, src->next);
		return (1);
	}
	if (make_list_and_addback(dst, new_data))
		error_exit("failed malloc in make redirection list");
	return (0);
}
