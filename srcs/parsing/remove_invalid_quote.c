/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_invalid_quote.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 01:29:15 by takwak            #+#    #+#             */
/*   Updated: 2025/02/03 22:00:29 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

char	*init_(char *src, int *n1, int *n2, int arr[2]);
int		is_invalid_quote(char *s, int *flag);
void	onoff_flag(char c, int flag[2]);

char	*remove_invalid_quote(char *src)
{
	int		res_idx;
	int		src_idx;
	int		flag[2];
	char	*res;

	res = init_(src, &res_idx, &src_idx, flag);
	if (!res)
		return (NULL);
	while (src[src_idx])
	{
		if (src_idx == 0 || (src[src_idx] != '\'' && src[src_idx] != '\"'))
		{
			onoff_flag(src[src_idx], flag);
			res[res_idx++] = src[src_idx++];
		}
		else
		{
			onoff_flag(src[src_idx], flag);
			if (is_invalid_quote(&src[src_idx], flag))
				src_idx++;
			else
				res[res_idx++] = src[src_idx++];
		}
	}
	return (res);
}

char	*init_(char *src, int *n1, int *n2, int arr[2])
{
	char	*res;

	res = (char *)ft_calloc((ft_strlen(src) + 1), sizeof(char));
	*n1 = 0;
	*n2 = 0;
	arr[0] = 0;
	arr[1] = 0;
	return (res);
}

int	is_invalid_quote(char *s, int *flag)
{
	if (*s == '\'')
	{
		if (flag[0] && ft_isalnum(*(s - 1)))
			return (1);
		if (!flag[0] && ft_isalnum(*(s + 1)))
			return (1);
	}
	if (*s == '\"')
	{
		if (flag[1] && ft_isalnum(*(s - 1)))
			return (1);
		if (!flag[1] && ft_isalnum(*(s + 1)))
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
