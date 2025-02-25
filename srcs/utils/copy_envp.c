/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:05:06 by takwak            #+#    #+#             */
/*   Updated: 2025/02/14 22:21:52 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	**copy_envp(char **envp)
{
	int		size;
	char	**dst;
	int		i;

	size = 0;
	while (envp[size])
		size++;
	dst = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (envp[i])
	{
		dst[i] = ft_strdup(envp[i]);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
