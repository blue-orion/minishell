/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:17:33 by takwak            #+#    #+#             */
/*   Updated: 2025/02/27 20:17:33 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	end_process(t_cmd *info, t_node *root)
{
	if (info->envp)
		free_pptr((void **)info->envp);
	free(info->input_buf);
	free_pptr((void **)info->cmd_buf);
	treeclear(info->root);
	close(info->stdfd[INPUT]);
	close(info->stdfd[OUTPUT]);
}
