/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:37:21 by takwak            #+#    #+#             */
/*   Updated: 2025/02/14 17:52:03 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	print_type(int type)
{
	if (type == SENTENSE)
		printf("type : SENTENSE\n");
	if (type == SINGLE_QUOTE)
		printf("type : SINGLE_QUOTE\n");
	if (type == DOUBLE_QUOTE)
		printf("type : DOUBLE_QUOTE\n");
	if (type == PARENTHESIS)
		printf("type : PARENTHESIS\n");
	if (type == SEPARATOR)
		printf("type : SEPARATOR\n");
	if (type == PIPE)
		printf("type : PIPE\n");
	if (type == AND)
		printf("type : AND\n");
	if (type == OR)
		printf("type : OR\n");
	if (type == AMPER)
		printf("type : AMPER\n");
	if (type == SEMI)
		printf("type : SEMI\n");
	if (type == CMD)
		printf("type : CMD\n");
	if (type == REDIRECTS)
		printf("type : REDIRECTS\n");
	if (type == IN)
		printf("type : IN\n");
	if (type == OUT)
		printf("type : OUT\n");
	if (type == HERE_DOC)
		printf("type : HERE_DOC\n");
	if (type == APPEND)
		printf("type : APPEND\n");
	if (type == SIMPLE_CMD)
		printf("type : SIMPLE_CMD\n");
	if (type == FILE_NAME)
		printf("type : FILE_NAME\n");
}

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
		print_type(data->type);
		printf("invalid : %d\n", data->invalid);
		printf("text : %s\n", data->text);
		// printf("index : [%d:%d]\n", data->start, data->end);
		cur = cur->next;
		i++;
	}
}

