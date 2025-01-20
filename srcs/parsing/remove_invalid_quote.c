/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_invalid_quote.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 01:29:15 by takwak            #+#    #+#             */
/*   Updated: 2025/01/20 01:29:15 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*remove_invalid_quote(char *src)
{
	char	*dst;
	int		src_len;
	int		dst_idx;
	int		src_idx;
	int		flag;

	src_len = ft_strlen(src);
	dst = (char *)malloc(sizeof(char) * src_len + 1);
	if (!dst)
		return (NULL);
	dst_idx = 0;
	src_idx = 0;
	flag = 0;
	dst[dst_idx++] = src[src_idx++];
	while (src[src_idx])
	{
		if (src[src_idx] != '\'' && src[src_idx] != '\"')
			dst[dst_idx++] = src[src_idx++];
		else
		{
			flag = !flag;
			if (flag && src[src_idx - 1] != ' ')
				src_idx++;
			else if (!flag && (src[src_idx + 1] != ' ' && src[src_idx + 1] != '\0'))
				src_idx++;
			else
				dst[dst_idx++] = src[src_idx++];
		}
	}
	dst[dst_idx] = '\0';
	return (dst);
}
