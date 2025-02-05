/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:06:56 by takwak            #+#    #+#             */
/*   Updated: 2025/02/05 21:06:56 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tree.h"

char	**list_to_str(t_list *head)
{
	t_list	*cur;
	int		cnt;
	char	**res;
	int		i;
	t_data	*cur_data;

	cur = head;
	cur_data = (t_data *)head->content;
	cnt = ft_lstsize(head);
	// res = (char **)malloc(sizeof(char *) * (cnt + 1));
	i = 0;
	while (cur)
	{
		// res[i] = ((t_data *)cur->content)->text;
		i++;
		cur = cur->next;
	}
	res = ft_split(cur_data->text, ' ');
	// res[3] = NULL;
	return (res);
}
