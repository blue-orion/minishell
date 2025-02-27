/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:06:56 by takwak            #+#    #+#             */
/*   Updated: 2025/02/27 19:20:20 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	interpret_env_all(t_list *head, t_cmd *info);

int	get_size(t_cmd *info, t_list *head)
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

char	**list_to_str(t_cmd *info, t_list *head)
{
	int		i;
	char	**res;
	int		size;
	t_data	*data;

	interpret_env_all(head, info);
	remove_invalid_quote(head);
	// if (interpret_wildcard(info, data))
	// 	return (-1);
	size = get_size(info, head);
	if (size <= 0)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (head)
	{
		data = (t_data *)head->content;
		if (data->type == DOUBLE_QUOTE || data->type == SINGLE_QUOTE)
			res[i++] = ft_strdup(data->text);
		else
			i += split_dup(res + i, data->text);
		head = head->next;
	}
	res[i] = NULL;
	return (res);
}

void	interpret_env_all(t_list *head, t_cmd *info)
{
	t_data	*data;
	char	*past;

	while (head)
	{
		data = (t_data *)head->content;
		if (data->type == SINGLE_QUOTE || !ft_strchr(data->text, '$'))
		{
			head = head->next;
			continue ;
		}
		past = data->text;
		data->text = interpret_env(data->text, info);
		free(past);
		head = head->next;
	}
}
