/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_invalid_quote.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 01:29:15 by takwak            #+#    #+#             */
/*   Updated: 2025/01/21 23:38:30 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	init_(int *a, int *b, int c[2]);

int	is_invalid_quote(char *s, int *flag)
{
	if (*s == '\'')
	{
		if (flag[0] && !is_metachar(*(s - 1)))
			return (1);
		if (!flag[0] && !is_metachar(*(s + 1)))
			return (1);
	}
	if (*s == '\"')
	{
		if (flag[1] && !is_metachar(*(s - 1)))
			return (1);
		if (!flag[1] && !is_metachar(*(s + 1)))
			return (1);
	}
	return (0);
}

void	onoff_flag(char c, int flag[2])
{
	if (c == '\'')
		flag[0] = !flag[0];
	if (c == '\"')
		flag[1] = !flag[1];
}

char	*remove_invalid_quote(char *dst, char *src)
{
	int		dst_idx;
	int		src_idx;
	int		flag[2];

	init_(&dst_idx, &src_idx, flag);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dst)
		return (NULL);
	while (src[src_idx])
	{
		if (src_idx == 0 || (src[src_idx] != '\'' && src[src_idx] != '\"'))
		{
			onoff_flag(src[src_idx], flag);
			dst[dst_idx++] = src[src_idx++];
		}
		else
		{
			onoff_flag(src[src_idx], flag);
			if (is_invalid_quote(&src[src_idx], flag))
				src_idx++;
			else
				dst[dst_idx++] = src[src_idx++];
		}
	}
	dst[dst_idx] = '\0';
	return (dst);
}

void	init_(int *a, int *b, int c[2])
{
	*a = 0;
	*b = 0;
	c[0] = 0;
	c[1] = 0;
}
