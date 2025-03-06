/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_wildcard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:00:07 by takwak            #+#    #+#             */
/*   Updated: 2025/03/06 22:27:24 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	interpret_wildcard(t_list **head, t_cmd *info)
{
	t_list	*cur_lst;
	t_list	*past_lst;
	t_data	*cur_data;
	char	**split_text;

	cur_lst = *head;
	past_lst = NULL;
	while (cur_lst)
	{
		cur_data = cur_lst->content;
		if (cur_data->type == DOUBLE_QUOTE || cur_data->type == SINGLE_QUOTE
			|| !include_asterisk(cur_data->text))
		{
			move_next_list(&past_lst, cur_lst);
			continue ;
		}
		split_text = ft_split(((t_data *)cur_lst->content)->text, ' ');
		push_before_asterisk(*head, split_text);
		expand_asterisk(*head, split_text, 0);
		free_pptr((void **)split_text);
		cur_lst = del_and_move_next_list(head, past_lst, cur_lst);
	}
}
