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
	while (i < 4)
	{
		if ((long)meta[i] < min)
			min = (long)meta[i];
		i++;
	}
	if (i == 0)
		return (SINGLE_QUOTE);
	if (i == 1)
		return (DOUBLE_QUOTE);
	if (i == 2)
		return (PARENTHESIS);
	if (i == 3)
		return (' ');
	return (0);
}

char	find_metachar(char *str)
{
	char	*meta[4];

	meta[0] = ft_strchr(str, '\'');
	meta[1] = ft_strchr(str, '\"');
	meta[2] = ft_strchr(str, '(');
	meta[3] = ft_strchr(str, ' ');
	return (find_min(meta));
}
