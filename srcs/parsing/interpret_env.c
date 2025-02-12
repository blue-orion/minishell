/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:55:35 by takwak            #+#    #+#             */
/*   Updated: 2025/02/12 18:57:12 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include <stdlib.h>

int	count_len(char *src, char **envp);

char	*interpret_env(char *src, char **envp)
{
	char	tmp[4096];
	char	*res;
	int		res_idx;
	char	*value;
	char	name[4096];
	int		i;
	int		j;
	int		double_flag;
	int		single_flag;

	i = 0;
	double_flag = 0;
	single_flag = 0;
	res_idx = 0;
	res = (char *)malloc(sizeof(char) * (count_len(src, envp) + 1));
	while (src[i])
	{
		if (!single_flag && src[i] == '\"')
			double_flag = !double_flag;
		if (!double_flag && src[i] == '\'')
			single_flag = !single_flag;
		if (src[i] == '$')
		{
			if (!single_flag)
			{
				i++;
				j = 0;
				while (src[i + j] && !is_metachar(src[i + j]))
				{
					name[j] = src[i + j];
					j++;
				}
				name[j] = '\0';
				i += j;
				if (double_flag && src[i] == '\"')
					double_flag = !double_flag;
				value = ft_getenv(name, envp);
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

int	count_len(char *src, char **envp)
{
	int		len;
	char	*value;
	char	name[4096];
	int		i;
	int		j;
	int		double_flag;
	int		single_flag;

	i = 0;
	len = 0;
	double_flag = 0;
	single_flag = 0;
	while (src[i])
	{
		if (!single_flag && src[i] == '\"')
			double_flag = !double_flag;
		if (!double_flag && src[i] == '\'')
			single_flag = !single_flag;
		if (src[i] == '$')
		{
			if (!single_flag)
			{
				j = 0;
				while (src[i + j] && !is_metachar(src[i + j]))
				{
					name[j] = src[i + j];
					j++;
				}
				name[j] = '\0';
				value = ft_getenv(name, envp);
				len += ft_strlen(value);
				i++;
				len++;
			}
		}
		len++;
		i++;
	}
	return (len);
}
