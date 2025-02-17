/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_invalid_quote.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 01:29:15 by takwak            #+#    #+#             */
/*   Updated: 2025/02/11 19:32:53 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#define SINGLE 0
#define DOUBLE 1

char	*init_source(char *src, int *n1, int *n2, int arr[2]);
int		is_invalid_quote(char *s, int start_idx, int *flag);
void	onoff_flag(char c, int flag[2]);

char	*remove_invalid_quote(char *src)
{
	int		res_idx;
	int		src_idx;
	int		flag[2];
	char	*res;

	res = init_source(src, &res_idx, &src_idx, flag);
	if (!res)
		return (NULL);
	while (src[src_idx])
	{
		if (src[src_idx] != '\'' && src[src_idx] != '\"')
			res[res_idx++] = src[src_idx++];
		else
		{
			if (is_invalid_quote(src, src_idx, flag))
			{
				if (src[src_idx] == '\'')
				{
					src_idx++;
					while (src[src_idx] != '\'')
						res[res_idx++] = src[src_idx++];
				}
				if (src[src_idx] == '\"')
				{
					src_idx++;
					while (src[src_idx] != '\"')
						res[res_idx++] = src[src_idx++];
				}
				src_idx++;
			}
			else
			{
				if (src[src_idx] == '\'')
				{
					res[res_idx++] = src[src_idx++];
					while (src[src_idx] != '\'')
						res[res_idx++] = src[src_idx++];
				}
				if (src[src_idx] == '\"')
				{
					res[res_idx++] = src[src_idx++];
					while (src[src_idx] != '\"')
						res[res_idx++] = src[src_idx++];
				}
				res[res_idx++] = src[src_idx++];
			}
		}
	}
	return (res);
}

char	*init_source(char *src, int *n1, int *n2, int arr[2])
{
	char	*res;

	res = (char *)ft_calloc((ft_strlen(src) + 1), sizeof(char));
	*n1 = 0;
	*n2 = 0;
	arr[0] = 0;
	arr[1] = 0;
	return (res);
}

int	is_invalid_quote(char *s, int start_idx, int *flag)
{
	int	i;

	i = start_idx;
	while (s[i])
	{
		onoff_flag(s[i], flag);
		if (s[i] == '\'')
		{
			if (flag[SINGLE] && i > 0 && !is_metachar(s[i - 1]))
				return (1);
			if (!flag[SINGLE] && s[i + 1] && !is_metachar(s[i + 1]))
				return (1);
		}
		if (s[i] == '\"')
		{
			if (flag[DOUBLE] && i > 0 && !is_metachar((s[i - 1])))
				return (1);
			if (!flag[DOUBLE] && s[i + 1] && !is_metachar(s[i + 1]))
				return (1);
		}
		i++;
	}
	return (0);
}

void	onoff_flag(char c, int flag[2])
{
	if (c == '\'')
		flag[SINGLE] = !flag[SINGLE];
	if (c == '\"')
		flag[DOUBLE] = !flag[DOUBLE];
}
