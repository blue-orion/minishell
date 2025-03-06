/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_util3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:25:46 by takwak            #+#    #+#             */
/*   Updated: 2025/03/06 22:26:29 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

int	push_entry(t_list **head, struct dirent *dp, t_wildcard *wc_info)
{
	t_data	*new_data;

	if (wc_info->dir_flag && dp->d_type != DT_DIR)
		return (0);
	new_data = (t_data *)malloc(sizeof(t_data));
	ft_memset(new_data, 0, sizeof(t_data));
	if (!new_data)
		error_exit("malloc failed in push_entry");
	if (wc_info->prefix_flag)
		new_data->text = ft_strjoin(wc_info->dir_path, dp->d_name);
	else
		new_data->text = ft_strdup(dp->d_name);
	if (wc_info->sub_pattern)
		new_data->text = ft_join_free(new_data->text, wc_info->sub_pattern);
	make_list_and_addback(head, new_data);
	return (1);
}

void	push_before_asterisk(t_list *head, char	**split_text)
{
	int		i;
	char	*res;
	t_data	*new_data;

	i = 0;
	res = ft_strdup("");
	if (!res)
		error_exit("malloc failed in interpret wildcard");
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
	if (!new_data)
		error_exit("malloc failed in interpret wildcard");
	ft_memset(new_data, 0, sizeof(t_data));
	new_data->text = res;
	new_data->type = CMD;
	make_list_and_addback(&head, new_data);
}

int	expand_asterisk(t_list *head, char **texts, int call_cnt)
{
	char			**token;
	t_wildcard		wc_info;
	t_data			*new_data;
	int				status;

	token = get_wildcard_token(texts);
	status = 0;
	while (token)
	{
		wc_info = extract_wildcard_info(&wc_info, *token);
		status = opendir_push_entries(head, &wc_info, call_cnt);
		if (!status)
		{
			if (call_cnt)
				break ;
			new_data = make_data(*token, DOUBLE_QUOTE, 0, ft_strlen(*token));
			if (!new_data)
				error_exit("malloc failed in expand_asterisk");
			make_list_and_addback(&head, new_data);
		}
		free_wc_info(&wc_info);
		token = get_wildcard_token(token + 1);
	}
	free_wc_info(&wc_info);
	return (status);
}

int	opendir_push_entries(t_list *head, t_wildcard *wc_info, int call_cnt)
{
	DIR				*dirp;
	struct dirent	*dp;
	int				status;

	status = 0;
	dirp = opendir(wc_info->dir_path);
	if (!dirp)
		return (0);
	dp = readdir(dirp);
	while (dp)
	{
		if (dp->d_name[0] != '.' && is_valid_entry(dp, wc_info))
		{
			if (wc_info->sub_pattern && include_asterisk(wc_info->sub_pattern))
				status += recursive_expand(dp->d_name, head, wc_info, call_cnt);
			else
				status += push_entry(&head, dp, wc_info);
		}
		dp = readdir(dirp);
	}
	closedir(dirp);
	return (status);
}

int	recursive_expand(char *entry, t_list *head, t_wildcard *wc_info, int call_cnt)
{
	char	**splited;
	int		status;

	status = 0;
	if (wc_info->prefix_flag)
	{
		entry = ft_strjoin(wc_info->dir_path, entry);
		entry = ft_join_free(entry, wc_info->sub_pattern);
	}
	else
		entry = ft_strjoin(entry, wc_info->sub_pattern);
	splited = ft_split(entry, ' ');
	status = expand_asterisk(head, splited, call_cnt + 1);
	free(entry);
	free_pptr((void **)splited);
	return (status);
}
