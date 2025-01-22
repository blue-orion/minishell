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

int	is_invalid_quote(char *s, int flag)
{
	if (flag && !is_metachar(*(s - 1)))
		return (1);
	if (!flag && !is_metachar(*(s + 1)))
		return (1);
	return (0);
}

char	*remove_invalid_quote(char *dst, char *src)
{
	int		dst_idx;
	int		src_idx;
	int		flag;

	dst_idx = 0;
	src_idx = 0;
	flag = 0;
	dst = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dst)
		return (NULL);
	while (src[src_idx])
	{
		if (src_idx == 0 || src[src_idx] != '\'' && src[src_idx] != '\"')
			dst[dst_idx++] = src[src_idx++];
		else
		{
			flag = !flag;
			if (is_invalid_quote(&src[src_idx], flag))
				src_idx++;
			else
				dst[dst_idx++] = src[src_idx++];
		}
	}
	dst[dst_idx] = '\0';
	return (dst);
}
