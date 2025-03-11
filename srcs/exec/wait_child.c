/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:13:05 by takwak            #+#    #+#             */
/*   Updated: 2025/03/11 21:31:21 by takwak           ###   ########.fr       */
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
	signal_setup(info);
}

void	set_exit_status(t_cmd *info, int status)
{
	if (WIFEXITED(status))
		g_exit_status = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		status = WTERMSIG(status);
		if (status == SIGTERM)
			ft_putstr_fd("Terminated", 1);
		if (status == SIGQUIT)
			ft_putstr_fd("Quit (core dumped)", 1);
		ft_putchar_fd('\n', 1);
		g_exit_status = status + 128;
	}
}
