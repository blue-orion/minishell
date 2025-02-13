/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:41:21 by takwak            #+#    #+#             */
/*   Updated: 2025/02/13 18:34:24 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"
#include "../../includes/utils.h"

void	declare_all(char **envp);
char	**declare_argv(char **cmd, char **envp);

int	ft_export(char **cmd, t_cmd *info)
{
	int		argc;
	char	**new_envp;
	int		envp_size;

	argc = getsize(cmd);
	if (argc == 1)
		declare_all(info->envp);
	else
	{
		new_envp = declare_argv(cmd + 1, info->envp);
		free_pptr((void **)info->envp);
		info->envp = new_envp;
	}
	return (0);
}

void	declare_all(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putendl_fd(envp[i], 1);
		i++;
	}
}

int	check_name(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[i]))
		return (-1);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]))
			return (-1);
		i++;
	}
	if (str[i] == '=')
		return (i);
	return (0);
}

char	**declare_argv(char **cmd, char **envp)
{
	char	**new_envp;
	int		envp_size;
	int		i;
	char	*new;
	int		value;

	envp_size = getsize(envp) + getsize(cmd);
	new_envp = (char **)malloc(sizeof(char *) * envp_size);
	i = 0;
	while (envp[i])
	{
		new_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	while (*cmd)
	{
		value = check_name(*cmd);
		if (value < 0)
		{
			put_error_msg("export", *cmd, "not a valid identifier");
		}
		if (value > 0)
			new_envp[i++] = ft_strdup(*cmd);
		cmd++;
	}
	new_envp[i] = NULL;
	return (new_envp);
}
