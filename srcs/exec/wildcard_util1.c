/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_wildcard_util2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:42:59 by takwak            #+#    #+#             */
/*   Updated: 2025/03/06 22:24:18 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

t_list	*del_and_move_next_list(t_list **head, t_list *past, t_list *cur)
{
	if (past)
	{
		past->next = cur->next;
		ft_lstdelone(cur, free_data);
		cur = past->next;
	}
	else
	{
		*head = cur->next;
		ft_lstdelone(cur, free_data);
		cur = *head;
	}
	return (cur);
}

t_list	*move_next_list(t_list **past, t_list *cur)
{
	*past = cur;
	cur = cur->next;
	return (cur);
}

int	include_asterisk(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '*')
			return (1);
		i++;
	}
	return (0);
}

void	free_wc_info(t_wildcard *wc_info)
{
	free(wc_info->dir_path);
	wc_info->dir_path = NULL;
	free(wc_info->match);
	wc_info->match = NULL;
	free(wc_info->sub_pattern);
	wc_info->sub_pattern = NULL;
}

char	**get_wildcard_token(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (include_asterisk(strs[i]))
			return (strs + i);
		i++;
	}
	return (NULL);
}
