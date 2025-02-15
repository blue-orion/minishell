/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:55:35 by takwak            #+#    #+#             */
/*   Updated: 2025/02/13 18:37:58 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include <stdlib.h>

int	count_len(char *src, int type, t_cmd *info);

char	*interpret_env(char *src, int type, t_cmd *info)
{
	char	*res;
	int		res_idx;
	char	*value;
	char	name[4096];
	int		i;
	int		j;

	i = 0;
	res_idx = 0;
	res = (char *)malloc(sizeof(char) * (count_len(src, type, info) + 1));
	while (src[i])
	{
		if (src[i] == '$')
		{
			if (type != SINGLE_QUOTE && src[i + 1])
			{
				i++;
				if (src[i] == '?')
				{
					value = ft_itoa(info->exit_status);
					i++;
				}
				else
				{
					j = 0;
					while (src[i + j] && !is_metachar(src[i + j]))
					{
						name[j] = src[i + j];
						j++;
					}
					name[j] = '\0';
					i += j;
					value = ft_getenv(name, info->envp);
				}
				if (value)
				{
					j = 0;
					while (value[j])
						res[res_idx++] = value[j++];
				}
			}
			res[res_idx++] = src[i++];
		}
		res[res_idx++] = src[i++];
	}
	res[res_idx] = '\0';
	return (res);
}

int	count_len(char *src, int type, t_cmd *info)
{
	int		len;
	char	*value;
	char	name[4096];
	int		i;
	int		j;

	i = 0;
	len = 0;
	while (src[i])
	{
		if (src[i] == '$')
		{
			if (type != SINGLE_QUOTE)
			{
				i++;
				if (src[i] == '?')
				{
					value = ft_itoa(info->exit_status);
					i++;
				}
				else
				{
					j = 0;
					while (src[i + j] && !is_metachar(src[i + j]))
					{
						name[j] = src[i + j];
						j++;
					}
					name[j] = '\0';
					i += j;
					value = ft_getenv(name, info->envp);
				}
				len += ft_strlen(value);
				len++;
			}
		}
		len++;
		i++;
	}
	return (len);
}
