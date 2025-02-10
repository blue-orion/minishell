/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:41:21 by takwak            #+#    #+#             */
/*   Updated: 2025/02/07 22:41:21 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"
#include "../../includes/utils.h"

void	declare_all(char **envp);
int	declare_argv(char **cmd, char **envp);

int	ft_export(char **cmd, char **envp)
{
	int		argc;
	char	**new_envp;
	int		envp_size;

	argc = getsize(cmd);
	if (argc == 1)
		declare_all(envp);
	else
	{
		declare_argv(cmd, envp);
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

int	declare_argv(char **cmd, char **envp)
{
	char	**new_envp;
	int		envp_size;
	int		i;
	char	*new;
	int		value;

	envp_size = getsize(envp) + getsize(cmd);
	new_envp = (char **)malloc(sizeof(char *) * envp_size);
	i = 0;
	while (new_envp[i])
		i++;
	while (*cmd)
	{
		value = check_name(cmd);
		if (check_name(cmd))
		{

		}
	}
}
