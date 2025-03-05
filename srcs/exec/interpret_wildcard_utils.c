/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_wildcard_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:05:32 by takwak            #+#    #+#             */
/*   Updated: 2025/03/05 21:54:04 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

char	*get_dir_path(char *text);
char	*get_match_and_sub_pattern(t_wildcard *wc_info, char *text);

void	push_entry(t_list **head, char *entry, t_wildcard *wc_info)
{
	t_data	*new_data;

	new_data = (t_data *)malloc(sizeof(t_data));
	ft_memset(new_data, 0, sizeof(t_data));
	if (!new_data)
		error_exit("malloc failed in push_entry");
	if (wc_info->prefix_flag)
		new_data->text = ft_strjoin(wc_info->dir_path, entry);
	else
		new_data->text = ft_strdup(entry);
	if (wc_info->sub_pattern)
		new_data->text = ft_join_free(new_data->text, wc_info->sub_pattern);
	make_list_and_addback(head, new_data);
}

t_wildcard	extract_wildcard_info(t_wildcard *wc_info, char *wildcard_token)
{
	wc_info->dir_path = get_dir_path(wildcard_token);
	wc_info->prefix_flag = 1;
	if (wc_info->dir_path == NULL)
	{
		wc_info->dir_path = getcwd(NULL, 1024);
		wc_info->prefix_flag = 0;
	}
	wc_info->match = get_match_and_sub_pattern(wc_info, wildcard_token);
	wc_info->dir_flag = 0;
	if (wc_info->sub_pattern)
		wc_info->dir_flag = 1;
	return (*wc_info);
}

char	*get_dir_path(char *text)
{
	int		last_slash;
	char	*path;
	int		i;

	i = 0;
	last_slash = -1;
	while (text[i])
	{
		if (text[i] == '/')
			last_slash = i;
		if (text[i] == '*')
			break ;
		i++;
	}
	if (last_slash == -1)
		return (NULL);
	path = ft_substr(text, 0, last_slash + 1);
	if (!path)
		error_exit("ft_substr failed in find_dir_path");
	return (path);
}

char	*get_match_and_sub_pattern(t_wildcard *wc_info, char *text)
{
	int		i;
	int		j;
	int		last_slash;

	i = 0;
	last_slash = -1;
	while (text[i])
	{
		if (text[i] == '/')
			last_slash = i;
		if (text[i] == '*')
		{
			j = i;
			while (text[j] && text[j] != '/')
				j++;
			break ;
		}
		i++;
	}
	if (text[j])
	{
		wc_info->match = ft_substr(text, last_slash + 1, j - last_slash - 1);
		wc_info->sub_pattern = ft_substr(text, j, ft_strlen(text) - j);
	}
	else
	{
		wc_info->match = ft_substr(text, last_slash + 1, j - last_slash + 1);
		wc_info->sub_pattern = NULL;
	}
	return (wc_info->match);
}

char	*extract_match(char *text)
{
	char	*match;
	int		i;
	
	i = 0;
	while (text[i])
	{
		if (text[i] == '*')
		{
			match = ft_substr(text, 0, i);
			if (!match)
				error_exit("ft_substr failed in extract_match");
			return (match);
		}
		i++;
	}
	return (NULL);
}

int	check_match_pattern(char *f_name, char *token)
{
	int		i;
	char	*match;
	char	*prefix;
	char	*suffix;
	int		match_len;

	i = 0;
	match_len = 0;
	prefix = extract_match(token);
	if (ft_strlen(prefix) != 0 && ft_strncmp(f_name, prefix, ft_strlen(prefix)))
	{
		free(prefix);
		return (0);
	}
	match = extract_match(token);
	while (match)
	{
		if (ft_strlen(match) == 0)
		{
			match_len += 1;
			match = extract_match(token + match_len);
			continue ;
		}
		while (f_name[i])
		{
			if (!ft_strncmp(&f_name[i], match, ft_strlen(match)))
			{
				i += ft_strlen(match) + 1;
				break ;
			}
			i++;
		}
		if (!f_name[i])
			return (0);
		match_len += ft_strlen(match) + 1;
		free(match);
		match = extract_match(token + match_len);
	}
	match = token + match_len;
	if (*match && ft_strncmp(f_name + ft_strlen(f_name) - ft_strlen(match), match, ft_strlen(match)))
		return (0);
	return (1);
}

int	is_valid_entry(struct dirent *dp, t_wildcard *wc_info)
{
	char	*f_name;

	f_name = dp->d_name;
	if (!check_match_pattern(dp->d_name, wc_info->match))
		return (0);
	if (wc_info->dir_flag && dp->d_type != DT_DIR)
		return (0);
	return (1);
}

char	*get_wildcard_token(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (include_asterisk(strs[i]))
			return (strs[i]);
		i++;
	}
	return (NULL);
}
