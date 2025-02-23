/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_wildcard_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:41:41 by takwak            #+#    #+#             */
/*   Updated: 2025/02/23 22:54:49 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	match_prefix(char *file, char *prefix)
{
	int	prefix_len;

	prefix_len = ft_strlen(prefix);
	if (ft_strncmp(file, prefix, prefix_len))
		return (0);
	return (1);
}

int	match_suffix(char *file, char *suffix)
{
	int	suffix_len;
	int	file_len;

	suffix_len = ft_strlen(suffix);
	file_len = ft_strlen(file);
	if (ft_strncmp(&file[file_len - suffix_len], suffix, suffix_len))
		return (0);
	return (1);
}

// char	*find_prefix(char *word)
// {
// 	int		i;
// 	char	*prefix;
//
// 	i = 0;
// 	if (!ft_strncmp(word, "*", 2))
// 		return (NULL);
// 	while (word[i])
// 	{
// 		if (word[i] == '*')
// 		{
// 			prefix = ft_substr(word, 0, i);
// 			if (!prefix)
// 			match[1] = ft_substr(word, i + 1, ft_strlen(word));
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
// }
