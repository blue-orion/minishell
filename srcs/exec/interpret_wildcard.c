/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_wildcard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:46:41 by takwak            #+#    #+#             */
/*   Updated: 2025/02/23 22:56:13 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"
#include <dirent.h>

int		is_wildcard(char *text);
char	*expand_wildcard(DIR *dirp, char *word);
int		find_match_str(char *match[2], char *word);
void	copy_wildcard_result(t_data *data, char **result);

int	interpret_wildcard(t_cmd *info, t_data *data)
{
	char	**words;
	char	*cur_path;
	char	*past;
	DIR		*dirp;
	int		i;

	cur_path = NULL;
	cur_path = getcwd(cur_path, 4096);
	words = ft_split(data->text, ' ');
	i = 0;
	while (words[i])
	{
		if (is_wildcard(words[i]))
		{
			dirp = opendir(cur_path);
			past = words[i];
			words[i] = expand_wildcard(dirp, words[i]);
			if (past != words[i])
				free(past);
			closedir(dirp);
		}
		words[i] = ft_join_free(words[i], " ");
		i++;
	}
	free(data->text);
	copy_wildcard_result(data, words);
	free_pptr((void **)words);
	free(cur_path);
	return (0);
}

void	copy_wildcard_result(t_data *data, char **result)
{
	int	i;

	i = 0;

	while (result[i])
	{
		if (i == 0)
			data->text = ft_strdup(result[i]);
		else
			data->text = ft_join_free(data->text, result[i]);
		i++;
		if (!data->text)
			error_exit("malloc failed in interpret wildcard");
	}
}

int	is_wildcard(char *text)
{
	int		i;

	i = 0;
	while (text[i])
	{
		if (text[i] == '*')
			return (1);
		i++;
	}
	return (0);
}

char	*expand_wildcard(DIR *dirp, char *word)
{
	struct dirent	*entry;
	char	*match[2];
	char	*tmp;

	entry = readdir(dirp);
	tmp = NULL;
	find_match_str(match, word);
	while (entry)
	{
		if (match_prefix(entry->d_name, match[0])
			&& match_suffix(entry->d_name, match[1])
			&& entry->d_name[0] != '.')
		{
			if (!tmp)
				tmp = ft_strdup(entry->d_name);
			else
				tmp = ft_join_free(tmp, entry->d_name);
			tmp = ft_join_free(tmp, " ");
		}
		entry = readdir(dirp);
	}
	if (!tmp)
		return (word);
	return (tmp);
}

int	find_match_str(char *match[2], char *word)
{
	int	i;

	i = 0;
	while (word[i])
	{
		if (word[i] == '*')
		{
			if (i == 0 && !word[i + 1])
			{
				match[0] = NULL;
				match[1] = NULL;
			}
			else
			{
				match[0] = ft_substr(word, 0, i);
				match[1] = ft_substr(word, i + 1, ft_strlen(word));
				return (0);
			}
		}
		i++;
	}
	return (1);
}
