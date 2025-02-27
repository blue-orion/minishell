/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:41:47 by takwak            #+#    #+#             */
/*   Updated: 2025/02/12 18:55:41 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"
#include "../../includes/utils.h"

int		unset_argv(char *to_unset, char **info, int env_size);
char	**unsetted_envp(int argc, char **env, int env_size);

int	ft_unset(char **cmd, t_cmd *info)
{
	char	**env;
	int		env_size;
	int		argc;
	int		i;

	argc = get_pptr_size((void **)cmd);
	if (argc == 1)
		return (0);
	env_size = get_pptr_size((void **)info->envp);
	i = 1;
	while (cmd[i])
	{
		if (unset_argv(cmd[i], info->envp, env_size))
			error_exit("malloc failed");
		i++;
	}
	info->envp = unsetted_envp(argc, info->envp, env_size);
	return (0);
}

char	**unsetted_envp(int argc, char **env, int env_size)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	j = 0;
	res = (char **)malloc(sizeof(char *) * env_size - argc + 2);
	while (i < env_size)
	{
		if (env[i])
			res[j++] = ft_strdup(env[i]);
		i++;
	}
	res[j] = NULL;
	i = 0;
	while (i < env_size)
		free(env[i++]);
	free(env);
	return (res);
}

int	unset_argv(char *to_unset, char **env, int env_size)
{
	int		i;
	char	*name;
	int		len;

	i = 0;
	name = ft_strjoin(to_unset, "=");
	len = ft_strlen(name);
	if (!name)
		return (-1);
	while (i < env_size)
	{
		if (env[i] && !ft_strncmp(env[i], name, len))
		{
			free(env[i]);
			env[i] = NULL;
		}
		i++;
	}
	free(name);
	return (0);
}
