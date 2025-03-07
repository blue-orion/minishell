/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_util4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:53:25 by takwak            #+#    #+#             */
/*   Updated: 2025/03/07 18:53:25 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

char	*extract_match(char *text);
int		check_prefix(char *f_name, char *text);
int		check_infix(char *f_name, int *i, char *match);
int		check_suffix(char *f_name, char *match);

int	check_match_pattern(char *f_name, char *token)
{
	int		i;
	char	*match;
	int		match_len;

	i = 0;
	match_len = 0;
	if (!check_prefix(f_name, token))
		return (0);
	match = extract_match(token);
	while (match)
	{
		if (!check_infix(f_name, &i, match))
			return (free(match), 0);
		match_len += ft_strlen(match) + 1;
		free(match);
		match = extract_match(token + match_len);
	}
	match = token + match_len;
	if (match[0] && !check_suffix(f_name, match))
		return (0);
	return (1);
}

int	check_prefix(char *f_name, char *text)
{
	char	*prefix;

	prefix = extract_match(text);
	if (ft_strlen(prefix) == 0)
	{
		free(prefix);
		return (1);
	}
	if (ft_strncmp(f_name, prefix, ft_strlen(prefix)))
	{
		free(prefix);
		return (0);
	}
	free(prefix);
	return (1);
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

int	check_infix(char *f_name, int *i, char *match)
{
	while (ft_strlen(match) != 0 && f_name[*i])
	{
		if (!ft_strncmp(&f_name[*i], match, ft_strlen(match)))
		{
			*i += ft_strlen(match) + 1;
			break ;
		}
		(*i)++;
	}
	if (ft_strlen(match) != 0 && !f_name[*i])
		return (0);
	return (1);
}

int	check_suffix(char *f_name, char *match)
{
	int	suffix_start;

	suffix_start = ft_strlen(f_name) - ft_strlen(match);
	if (ft_strncmp(f_name + suffix_start, match, ft_strlen(match)))
		return (0);
	return (1);
}
