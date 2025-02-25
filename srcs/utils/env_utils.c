/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:17:40 by takwak            #+#    #+#             */
/*   Updated: 2025/02/25 23:17:40 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	dup_env(char **dst, char **src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = ft_strdup(src[i]);
		if (!dst[i])
			error_exit("failed malloc in dup_env");
		i++;
	}
}

char	*get_name(char *str)
{
	int		i;
	char	*name;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	name = ft_substr(str, 0, i);
	if (!name)
		error_exit("failed malloc in get_name");
	return (name);
}

int	get_name_index(char *name, char **envp)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(name);
	while (envp[i])
	{
		if (!ft_strncmp(name, envp[i], len) && envp[i][len] == '=')
			return (i);
		i++;
	}
	return (-1);
}

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
		if (!ft_strncmp(env_name, name, ft_strlen(name) + 1))
		{
			res = ft_strchr(envp[i], '=') + 1;
			return (res);
		}
		i++;
	}
	return (NULL);
}
