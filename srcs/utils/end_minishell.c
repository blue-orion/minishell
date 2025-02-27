/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_resource.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:47:53 by root              #+#    #+#             */
/*   Updated: 2025/02/24 17:48:33 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	end_minishell(t_cmd *info)
{
	free_pptr((void **)info->envp);
	close(info->stdfd[INPUT]);
	close(info->stdfd[OUTPUT]);
	clear_history();
}
