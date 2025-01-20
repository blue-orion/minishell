/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:37:21 by takwak            #+#    #+#             */
/*   Updated: 2025/01/20 20:37:21 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	print_list(t_list *head)
{
	t_list	*cur;
	t_data	*data;
	int		i;
	
	i = 1;
	cur = head;
	while (cur)
	{
		data = (t_data *)cur->content;
		printf("----- node = %d -----\n", i);
		printf("type : %d\n", data->type);
		printf("text : %s\n", data->text);
		printf("index : [%d:%d]\n", data->start, data->end);
		cur = cur->next;
		i++;
	}
}

