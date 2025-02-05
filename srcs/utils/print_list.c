/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:37:21 by takwak            #+#    #+#             */
/*   Updated: 2025/02/05 16:45:41 by takwak           ###   ########.fr       */
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
		if (data->type == PIPE)
			printf("type : PIPE\n");
		if (data->type == AND)
			printf("type : AND\n");
		if (data->type == OR)
			printf("type : OR\n");
		if (data->type == AMPER)
			printf("type : AMPER\n");
		if (data->type == SEMI)
			printf("type : SEMI\n");
		if (data->type == CMD)
			printf("type : CMD\n");
		if (data->type == REDIRECTS)
			printf("type : REDIRECTS\n");
		if (data->type == IN)
			printf("type : IN\n");
		if (data->type == OUT)
			printf("type : OUT\n");
		if (data->type == HERE_DOC)
			printf("type : HERE_DOC\n");
		if (data->type == APPEND)
			printf("type : APPEND\n");
		if (data->type == SIMPLE_CMD)
			printf("type : SIMPLE_CMD\n");
		if (data->type == FILE_NAME)
			printf("type : FILE_NAME\n");
		printf("text : %s\n", data->text);
		// printf("index : [%d:%d]\n", data->start, data->end);
		cur = cur->next;
		i++;
	}
}

