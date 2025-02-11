/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:55:35 by takwak            #+#    #+#             */
/*   Updated: 2025/02/11 16:40:31 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include <stdlib.h>

int	count_len(char *src);

char	*interpret_env(char *src)
{
	char	tmp[4096];
	char	*res;
	int		res_idx;
	char	*env;
	char	name[4096];
	int		i;
	int		j;
	int		double_flag;
	int		single_flag;

	i = 0;
	double_flag = 0;
	single_flag = 0;
	res_idx = 0;
	printf("len = %d\n", count_len(src));
	res = (char *)malloc(sizeof(char) * (count_len(src) + 1));
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
				while (src[i + 1 + j] && !is_metachar(src[i + 1 + j]))
				{
					name[j] = src[i + 1 + j];
					j++;
				}
				i += j + 1;
				if (double_flag && src[i] == '\"')
					double_flag = !double_flag;
				name[j] = '\0';
				printf("name = %s\n", name);
				env = getenv(name);
				if (env)
				{
					j = 0;
					while (env[j])
						res[res_idx++] = env[j++];
				}
			}
		}
		res[res_idx++] = src[i++];
	}
	res[res_idx] = '\0';
	return (res);
}

int	count_len(char *src)
{
	int		len;
	char	*env;
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
				while (src[i + 1 + j] && !is_metachar(src[i + 1 + j]))
				{
					name[j] = src[i + 1 + j];
					j++;
				}
				name[j] = '\0';
				env = getenv(name);
				len += ft_strlen(env);
			}
		}
		len++;
		i++;
	}
	return (len);
}
