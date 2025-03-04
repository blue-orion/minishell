/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_wildcard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:00:07 by takwak            #+#    #+#             */
/*   Updated: 2025/03/05 01:33:38 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

int		include_asterisk(char *str);
void	push_before_asterisk(t_list *head, char	**split_text);
void	expand_asterisk(t_cmd *info, t_list *head, char **texts);


void	interpret_wildcard(t_list *head, t_cmd *info)
{
	t_list	*cur_lst;
	t_list	*past_lst;
	char	**split_text;

	cur_lst = head;
	while (cur_lst)
	{
		if (include_asterisk(((t_data *)cur_lst->content)->text))
		{
			split_text = ft_split(((t_data *)cur_lst->content)->text, ' ');
			push_before_asterisk(head, split_text);
			expand_asterisk(info, head, split_text);
			past_lst->next = cur_lst->next;
			ft_lstdelone(cur_lst, free_data);
			cur_lst = past_lst->next;
			free_pptr((void **)split_text);
		}
		else
		{
			past_lst = cur_lst;
			cur_lst = cur_lst->next;
		}
	}
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

void	push_before_asterisk(t_list *head, char	**split_text)
{
	int		i;
	char	*res;
	t_data	*new_data;

	i = 0;
	res = ft_strdup("");
	if (!include_asterisk(split_text[i]))
	{
		res = ft_join_free(res, split_text[i]);
		i++;
	}
	if (!res[0])
	{
		free(res);
		return ;
	}
	new_data = (t_data *)malloc(sizeof(t_data));
	ft_memset(new_data, 0, sizeof(t_data));
	if (!new_data)
		error_exit("malloc failed in interpret wildcard");
	new_data->text = res;
	new_data->type = CMD;
	make_list_and_addback(&head, new_data);
}

void	expand_asterisk(t_cmd *info, t_list *head, char **texts)
{
	DIR				*dirp;
	char			*token;
	struct dirent	*dp;
	t_wildcard		wc_info;

	token = get_wildcard_token(texts);
	wc_info = extract_wildcard_info(&wc_info, token);
	printf("cur_dir = %s\n", wc_info.dir_path);
	dirp = opendir(wc_info.dir_path);
	dp = readdir(dirp);
	while (dp)
	{
		if (is_valid_entry(dp, &wc_info))
			push_entry(&head, dp->d_name, &wc_info);
		dp = readdir(dirp);
	}
}
