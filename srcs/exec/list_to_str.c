/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:06:56 by takwak            #+#    #+#             */
/*   Updated: 2025/03/21 19:55:05 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

static int	get_size(t_list *head);
int			split_dup(char **dst, char *src);

char	**list_to_str(t_list **head)
{
	int		i;
	char	**res;
	int		size;
	t_list	*cur_lst;
	t_data	*data;

	size = get_size(*head);
	if (size <= 0)
		return (NULL);
	res = (char **)ft_calloc(size + 1, sizeof(char *));
	i = 0;
	cur_lst = *head;
	while (cur_lst)
	{
		data = (t_data *)cur_lst->content;
		if (data->type == DOUBLE_QUOTE || data->type == SINGLE_QUOTE)
			res[i++] = ft_strdup(data->text);
		else
			i += split_dup(res + i, data->text);
		cur_lst = cur_lst->next;
	}
	return (res);
}

static int	get_size(t_list *head)
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
			cnt += get_pptr_size((void **)tmp);
			free_pptr((void **)tmp);
		}
		head = head->next;
	}
	return (cnt);
}

int	split_dup(char **dst, char *src)
{
	int		i;
	char	**tmp;

	tmp = ft_split(src, ' ');
	if (!tmp)
		error_exit("split_dup failed");
	i = 0;
	while (tmp[i])
	{
		dst[i] = ft_strdup(tmp[i]);
		i++;
	}
	free_pptr((void **)tmp);
	return (i);
}
