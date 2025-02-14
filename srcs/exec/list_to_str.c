/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:06:56 by takwak            #+#    #+#             */
/*   Updated: 2025/02/14 18:23:02 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
char	*join_pieces(t_list *head);

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

char	**list_to_str(t_cmd *info, t_list *head)
{
	int		i;
	int		j;
	char	**res;
	char	**tmp;
	char	*past;
	t_data	*data;

	res = (char **)malloc(sizeof(char *) * (check_size(head) + 1));
	i = 0;
	while (head)
	{
		data = (t_data *)head->content;
		past = data->text;
		data->text = interpret_env(data->text, data->type, info->envp);
		free(past);
		past = data->text;
		data->text = remove_invalid_quote(data->text);
		free(past);
		if (data->type == DOUBLE_QUOTE || data->type == SINGLE_QUOTE)
			res[i++] = ft_strdup(data->text);
		else
		{
			if (head->next && ((t_data *)head->next->content)->invalid)
			{
				data->text = join_pieces(head);
				head = head->next->next;
			}
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

char	*join_pieces(t_list *head)
{
	t_list	*cur_lst;
	char	*past;
	t_data	*head_data;
	t_data	*next_data;

	cur_lst = head;
	head_data = (t_data *)head->content;
	next_data = (t_data *)head->next->content;
	past = head_data->text;
	head_data->text = ft_strjoin(head_data->text, next_data->text);
	free(past);
	cur_lst = head->next;
	next_data = (t_data *)cur_lst->next->content;
	past = head_data->text;
	head_data->text = ft_strjoin(head_data->text, next_data->text);
	free(past);
	return (head_data->text);
}
