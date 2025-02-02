/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_redirection_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:48:08 by takwak            #+#    #+#             */
/*   Updated: 2025/02/02 16:14:58 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	redirection_list(t_list **head, t_data *data)
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
		return (perror("malloc failed"), -1);
	if (make_list_and_addback(head, new_data))
		return (perror("malloc failed"), -1);
	new_data = make_data(data->text, FILE_NAME, end, ft_strlen(data->text));
	if (!new_data)
		return (perror("malloc failed"), -1);
	if (make_list_and_addback(head, new_data))
		return (perror("malloc failed"), -1);
	return (0);
}

t_list	*make_redirection_list(t_list *head)
{
	t_data	*cur_data;
	t_list	*new_lst;

	new_lst = NULL;
	cur_data = (t_data *)head->content;
	if (redirection_list(&new_lst, cur_data))
		return (NULL);
	return (new_lst);
}
