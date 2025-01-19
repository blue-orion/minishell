/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_metachar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:05:58 by takwak            #+#    #+#             */
/*   Updated: 2025/01/19 20:22:58 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/libft.h"
#include <limits.h>

int	find_min(char *meta[4])
{
	long	min;
	int		i;

	min = LONG_MAX;
	i = 0;
	while (i < 3)
	{
		if ((long)meta[i] != 0 && (long)meta[i] < min)
			min = (long)meta[i];
		i++;
	}
	if (min == (long)meta[0])
		return (SINGLE_QUOTE);
	if (min == (long)meta[1])
		return (DOUBLE_QUOTE);
	if (min == (long)meta[2])
		return (PARENTHESIS);
	return (0);
}

char	find_metachar(char *str, int start)
{
	char	*meta[4];

	meta[0] = ft_strchr(&str[start], '\'');
	meta[1] = ft_strchr(&str[start], '\"');
	meta[2] = ft_strchr(&str[start], '(');
	return (find_min(meta));
}
