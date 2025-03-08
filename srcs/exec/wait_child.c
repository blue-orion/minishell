/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:13:05 by takwak            #+#    #+#             */
/*   Updated: 2025/03/07 21:00:24 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_signal.h"
#include "../../includes/exec.h"
#include <sys/wait.h>

void	set_exit_status(t_cmd *info, int status);

void	wait_child(t_cmd *info, pid_t child_pid)
{
	int		status;
	pid_t	wpid;

	signal(SIGINT, SIG_IGN);
	wpid = waitpid(child_pid, &status, 0);
	if (wpid < 0 && !WIFSIGNALED(status))
		perror("waitpid error");
	set_exit_status(info, status);
	printf("pid : %d, exit_status = %d\n", child_pid, info->exit_status);
	signal_setup();
}

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
