/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:37:21 by takwak            #+#    #+#             */
/*   Updated: 2025/01/22 02:39:31 by takwak           ###   ########.fr       */
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
		printf("----- list = %d -----\n", i);
		if (data->type == SENTENSE)
			printf("type : SENTENSE\n");
		if (data->type == SINGLE_QUOTE)
			printf("type : SINGLE_QUOTE\n");
		if (data->type == DOUBLE_QUOTE)
			printf("type : DOUBLE_QUOTE\n");
		if (data->type == PARENTHESIS)
			printf("type : PARENTHESIS\n");
		if (data->type == SEPARATOR)
			printf("type : SEPARATOR\n");
		if (data->type == CMD)
			printf("type : CMD\n");
		if (data->type == REDIRECTS)
			printf("type : REDIRECTS\n");
		if (data->type == SIMPLE_CMD)
			printf("type : SIMPLE_CMD\n");
		if (data->type == FILE_NAME)
			printf("type : FILE_NAME\n");
		printf("text : %s\n", data->text);
		printf("index : [%d:%d]\n", data->start, data->end);
		cur = cur->next;
		i++;
	}
}

