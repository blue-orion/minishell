/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:05:32 by takwak            #+#    #+#             */
/*   Updated: 2025/03/06 22:26:05 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

char	*get_dir_path(char *text);
char	*get_match_and_sub_pattern(t_wildcard *wc_info, char *text);

char	*preprocess_slash(char *text)
{
	int		i;
	int		j;
	char	*res;

	res = (char *)malloc(sizeof(char) * (ft_strlen(text) + 1));
	if (!res)
		error_exit("malloc failed in preprocess_slash");
	i = 0;
	j = 0;
	while (text[i])
	{
		if (text[i] == '/' && text[i + 1] && text[i + 1] == '/')
		{
			i++;
			continue ;
		}
		res[j++] = text[i++];
	}
	res[j] = '\0';
	return (res);
}

t_wildcard	extract_wildcard_info(t_wildcard *wc_info, char *wildcard_token)
{
	char	*str;

	str = preprocess_slash(wildcard_token);
	wc_info->dir_path = get_dir_path(str);
	wc_info->prefix_flag = 1;
	if (wc_info->dir_path == NULL)
	{
		wc_info->dir_path = getcwd(NULL, 1024);
		wc_info->prefix_flag = 0;
	}
	wc_info->match = get_match_and_sub_pattern(wc_info, str);
	wc_info->dir_flag = 0;
	if (wc_info->sub_pattern)
		wc_info->dir_flag = 1;
	free(str);
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
		if (!wc_info->sub_pattern)
			error_exit("malloc failed");
	}
	else
	{
		wc_info->match = ft_substr(text, last_slash + 1, j - last_slash + 1);
		wc_info->sub_pattern = NULL;
	}
	if (!wc_info->match)
		error_exit("malloc failed");
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
	free(prefix);
	match = extract_match(token);
	while (match)
	{
		if (ft_strlen(match) == 0)
		{
			match_len += 1;
			free(match);
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
		{
			free(match);
			return (0);
		}
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
	if (wc_info->dir_flag && dp->d_type != DT_DIR && dp->d_type != DT_LNK)
		return (0);
	return (1);
}
