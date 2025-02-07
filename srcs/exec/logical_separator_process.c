/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_separator_process.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:34:19 by takwak            #+#    #+#             */
/*   Updated: 2025/02/07 18:34:19 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

void	logical_separator_process(t_cmd *info, t_node *cur_node)
{
	if (is_builtin_node(cur_node->left_child))
		exec_command();
	if (is_builtin_node(cur_node->right_child))
		exec_command();
}
