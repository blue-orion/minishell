/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:38:41 by takwak            #+#    #+#             */
/*   Updated: 2025/01/23 15:38:41 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	find_token(t_list *lst, int to_find)
{
	t_data	*data;
	t_list	*cur;

	cur = lst;
	while (cur)
	{
		data = (t_data *)cur->content;
		if (data->type == to_find)
			return (1);
		cur = cur->next;
	}
	return (0);
}
