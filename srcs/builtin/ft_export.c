/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:41:21 by takwak            #+#    #+#             */
/*   Updated: 2025/03/12 16:53:38 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"
#include "../../includes/utils.h"

void	declare_all(char **envp);
char	**make_new_env_set(char **cmd, char **envp);

int	ft_export(char **cmd, t_cmd *info)
{
	int		argc;
	char	**new_envp;

	argc = get_pptr_size((void **)cmd);
	if (argc == 1)
		declare_all(info->envp);
	else
	{
		new_envp = make_new_env_set(cmd + 1, info->envp);
		free_pptr((void **)info->envp);
		info->envp = new_envp;
	}
	return (g_exit_status);
}

void	declare_all(char **envp)
{
	int		i;
	char	*value;
	char	*name;

	i = 0;
	while (envp[i])
	{
		name = get_name(envp[i]);
		value = ft_getenv(name, envp);
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(name, 1);
		ft_putchar_fd('=', 1);
		ft_putchar_fd('\"', 1);
		ft_putstr_fd(value, 1);
		ft_putchar_fd('\"', 1);
		ft_putchar_fd('\n', 1);
		free(name);
		i++;
	}
}

int	is_valid_env_format(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[i]))
	{
		g_exit_status = 1;
		return (0);
	}
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]))
		{
			g_exit_status = 1;
			return (0);
		}
		i++;
	}
	if (i != 0 && str[i] == '=')
		return (i);
	g_exit_status = 1;
	return (0);
}

void	add_new_env(char **new_envp, char **cmd)
{
	int		i;
	char	*name;
	int		name_index;

	i = 0;
	while (new_envp[i])
		i++;
	while (*cmd)
	{
		if (!is_valid_env_format(*cmd))
			put_error_msg("export", *cmd, INVALID_IDENTIFIER);
		else
		{
			name = get_name(*cmd);
			name_index = get_name_index(name, new_envp);
			if (name_index >= 0)
				new_envp[name_index] = ft_strdup(*cmd);
			else
				new_envp[i++] = ft_strdup(*cmd);
			free(name);
		}
		cmd++;
	}
	new_envp[i] = NULL;
}

char	**make_new_env_set(char **cmd, char **envp)
{
	char	**new_envp;
	int		envp_size;

	envp_size = get_pptr_size((void **)envp) + get_pptr_size((void **)cmd);
	new_envp = (char **)malloc(sizeof(char *) * (envp_size + 1));
	if (!new_envp)
		error_exit("failed malloc in export");
	ft_memset(new_envp, 0, sizeof(char *) * (envp_size + 1));
	dup_env(new_envp, envp);
	add_new_env(new_envp, cmd);
	return (new_envp);
}
