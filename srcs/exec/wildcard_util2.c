/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:05:32 by takwak            #+#    #+#             */
/*   Updated: 2025/03/07 17:52:28 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

char	*preprocess_slash(char *text);
char	*get_dir_path(char *text);
char	*get_match_and_sub_pattern(t_wildc *wc_info, char *text);

int	is_valid_entry(struct dirent *dp, t_wildc *wc_info)
{
	char	*f_name;

	f_name = dp->d_name;
	if (!check_match_pattern(dp->d_name, wc_info->match))
		return (0);
	if (wc_info->dir_flag && dp->d_type != DT_DIR && dp->d_type != DT_LNK)
		return (0);
	return (1);
}

t_wildc	extract_wildcard_info(t_wildc *wc_info, char *wildcard_token)
{
	char	*str;

	ft_memset(wc_info, 0, sizeof(t_wildc));
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

char	*get_match_and_sub_pattern(t_wildc *wc_info, char *text)
{
	int	start;
	int	end;
	int	i;

	i = 0;
	start = 0;
	while (text[i] != '*')
	{
		if (text[i] == '/')
			start = i + 1;
		i++;
	}
	while (text[i] && text[i] != '/')
		i++;
	end = i;
	wc_info->match = ft_substr(text, start, end - start);
	if (!wc_info->match)
		error_exit("malloc failed");
	if (text[i] == '/')
	{
		wc_info->sub_pattern = ft_strdup(text + end);
		if (!wc_info->sub_pattern)
			error_exit("malloc failed");
	}
	return (wc_info->match);
}
