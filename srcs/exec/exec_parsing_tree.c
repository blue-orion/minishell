/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_parsing_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:14:59 by takwak            #+#    #+#             */
/*   Updated: 2025/02/06 01:08:10 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_parsing_tree(t_cmd *info, t_node *parent)
{
	t_data	*data;

	data = (t_data *)parent->head->content;
	if (data->type >> 3)
	{
		//SIMPLE_CMD node
		info->cmd = list_to_str(parent->head);
		printf("%s\n", *info->cmd);
		echo(info->cmd);
	}
	else if (data->type >> 4)
	{
		//SEPARATOR node
		//pipe 생성
		//left_child node fork
		//right_child node fork

	}
	else if (data->type >> 5)
	{
		//REDIRECTS node

	}
	else
	{
		exec_parsing_tree(info, parent->left_child);
		exec_parsing_tree(info, parent->right_child);
	}
}
