/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:12:19 by takwak            #+#    #+#             */
/*   Updated: 2025/03/11 21:48:35 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"
#include <sys/stat.h>

int	home_not_set(void);
int	too_many_args(void);
int	no_file_or_dir(char *arg);
int	not_a_directory(char *arg);

int	ft_cd(char **cmd, t_cmd *info)
{
	char	*home_path;
	int		size;

	size = get_pptr_size((void **)cmd);
	if (size > 2)
		return (too_many_args());
	if (!cmd[1] || !ft_strncmp(cmd[1], "~", 2))
	{
		home_path = ft_getenv("HOME", info->envp);
		if (!home_path)
			return (home_not_set());
		chdir(home_path);
		return (0);
	}
	if (access(cmd[1], F_OK))
		return (no_file_or_dir(cmd[1]));
	if (!is_dir(cmd[1]))
		return (not_a_directory(cmd[1]));
	chdir(cmd[1]);
	return (0);
}

int	too_many_args(void)
{
	put_error_msg("cd", NULL, TOO_MANY_ARGS);
	return (1);
}

int	home_not_set(void)
{
	put_error_msg("cd", NULL, HOME_NOT_SET);
	return (1);
}

int	no_file_or_dir(char *arg)
{
	put_error_msg("cd", arg, NO_FILE_OR_DIR);
	return (1);
}

int	not_a_directory(char *arg)
{
	put_error_msg("cd", arg, NOT_A_DIR);
	return (1);
}
