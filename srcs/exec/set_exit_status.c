/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exit_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:12:06 by takwak            #+#    #+#             */
/*   Updated: 2025/02/24 19:13:35 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "../../includes/struct.h"
#include <sys/wait.h>

void	set_exit_status(t_cmd *info, int status)
{
	if (WIFEXITED(status))
		info->exit_status = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		status = WTERMSIG(status);
		if (status == SIGTERM)
			ft_putendl_fd("Terminated", 1);
		info->exit_status = status + 128;
	}
}
