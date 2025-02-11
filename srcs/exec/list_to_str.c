/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:06:56 by takwak            #+#    #+#             */
/*   Updated: 2025/02/10 14:36:36 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	split_size(char **splited)
{
	int	cnt;

	cnt = 0;
	while (splited[cnt])
		cnt++;
	return (cnt);
}

int	check_size(t_list *head)
{
	int		cnt;
	char	**tmp;
	t_data	*data;

	cnt = 0;
	while (head)
	{
		data = (t_data *)head->content;
		if (data->type == DOUBLE_QUOTE || data->type == SINGLE_QUOTE)
			cnt++;
		else
		{
			tmp = ft_split(data->text, ' ');
			cnt += split_size(tmp);
			free_pptr((void **)tmp);
		}
		head = head->next;
	}
	return (cnt);
}

char	**list_to_str(t_list *head)
{
	int		i;
	int		j;
	char	**res;
	char	**tmp;
	t_data	*data;

	res = (char **)malloc(sizeof(char *) * (check_size(head) + 1));
	i = 0;
	while (head)
	{
		data = (t_data *)head->content;
		if (data->type == DOUBLE_QUOTE || data->type == SINGLE_QUOTE)
			res[i++] = ft_strdup(data->text);
		else
		{
			tmp = ft_split(data->text, ' ');
			j = 0;
			while (tmp[j])
				res[i++] = ft_strdup(tmp[j++]);
			free_pptr((void **)tmp);
		}
		head = head->next;
	}
	res[i] = NULL;
	return (res);
}
