/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:37:51 by takwak            #+#    #+#             */
/*   Updated: 2025/02/03 15:38:34 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_list	*find_redirection(t_list *head)
{
	t_list	*cur;
	t_data	*data;
	int		i;

	cur = head;
	while (cur)
	{
		data = (t_data *)cur->content;
		i = 0;
		while (data->text[i])
		{
			if (is_redirection(data->text + i))
				return (cur);
			i++;
		}
		cur = cur->next;
	}
	return (NULL);
}
