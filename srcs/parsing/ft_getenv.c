/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:41:02 by takwak            #+#    #+#             */
/*   Updated: 2025/02/11 19:46:54 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_getenv(char *name, char **envp)
{
	char	*res;
	int		i;
	int		j;
	char	env_name[4096];

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
		{
			env_name[j] = envp[i][j];
			j++;
		}
		env_name[j] = '\0';
		if(!ft_strncmp(env_name, name, ft_strlen(name) + 1))
		{
			res = ft_strchr(envp[i], '=') + 1;
			return (res);
		}
		i++;
	}
	return (NULL);
}
