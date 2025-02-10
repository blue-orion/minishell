/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:12:19 by takwak            #+#    #+#             */
/*   Updated: 2025/02/10 15:38:08 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

int	ft_cd(char **cmd)
{
	char	*home_path;
	int		size;

	size = getsize(cmd);
	if (size > 2)
	{
		put_error_msg("cd", NULL, "too many arguments");
		return (1);
	}
	home_path = getenv("HOME");
	if (!cmd[1])
		chdir(home_path);
	else
	{
		if (access(cmd[1], F_OK))
		{
			put_error_msg("cd", cmd[1], NO_FILE_OR_DIR);
			return (1);
		}
		chdir(cmd[1]);
	}
	return (0);
}
