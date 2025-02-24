/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:06:56 by takwak            #+#    #+#             */
/*   Updated: 2025/02/24 17:17:11 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	join_pieces(t_list *head);
void	interpret_env_all(t_list *head, t_cmd *info);

int	split_size(char **splited)
{
	int	cnt;

	cnt = 0;
	while (splited[cnt])
		cnt++;
	return (cnt);
}

int	check_size(t_cmd *info, t_list *head)
{
	int		cnt;
	char	**tmp;
	t_data	*data;

	cnt = 0;
	while (head)
	{
		data = (t_data *)head->content;
		if (is_empty_str(data->text))
		{
			head = head->next;
			continue ;
		}
		if (data->type == DOUBLE_QUOTE || data->type == SINGLE_QUOTE)
			cnt++;
		else
		{
			// if (interpret_wildcard(info, data))
			// 	return (-1);
			tmp = ft_split(data->text, ' ');
			cnt += split_size(tmp);
			free_pptr((void **)tmp);
		}
		head = head->next;
	}
	return (cnt);
}

char	**list_to_str(t_cmd *info, t_list *head)
{
	int		i;
	int		j;
	char	**res;
	char	**tmp;
	char	*past;
	int		size;
	t_data	*data;

	i = 0;
	interpret_env_all(head, info);
	join_pieces(head);
	size = check_size(info, head);
	if (size <= 0)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (size + 1));
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

void	join_pieces(t_list *head)
{
	t_list	*past_lst;
	t_list	*cur_lst;
	t_list	*free_lst;
	t_data	*past_data;
	t_data	*cur_data;
	t_data	*next_data;

	cur_lst = head;
	past_lst = NULL;
	while (cur_lst)
	{
		cur_data = (t_data *)cur_lst->content;
		if (cur_data->invalid[1])
		{
			free_lst = cur_lst->next;
			next_data = (t_data *)cur_lst->next->content;
			cur_data->text = ft_strjoin(cur_data->text, next_data->text);
			cur_lst->next = cur_lst->next->next;
			ft_lstdelone(free_lst, free_data);
		}
		if (cur_data->invalid[0])
		{
			past_data->text = ft_strjoin(past_data->text, cur_data->text);
			past_lst->next = cur_lst->next;
			ft_lstdelone(cur_lst, free_data);
			cur_lst = past_lst;
		}
		past_lst = cur_lst;
		past_data = (t_data *)past_lst->content;
		cur_lst = cur_lst->next;
	}
}
