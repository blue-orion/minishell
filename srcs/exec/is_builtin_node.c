/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:05:16 by takwak            #+#    #+#             */
/*   Updated: 2025/02/13 18:31:55 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

t_node	*find_simple_cmd(t_node *root)
{
	t_node	*cur_node;
	t_data	*data;

	cur_node = root;
	if (!cur_node->head)
		cur_node = cur_node->right_child;
	data = (t_data *)cur_node->head->content;
	while (data->type != SIMPLE_CMD)
	{
		cur_node = cur_node->right_child;
		data = (t_data *)cur_node->head->content;
	}
	return (cur_node);
}

int	is_builtin_node(t_cmd *info, t_node *root)
{
	t_node	*cur_node;
	char	**tmp;
	int		result;

	if (root->type != CMD)
		return (0);
	cur_node = find_simple_cmd(root);
	tmp = list_to_str(info, cur_node->head);
	result = is_builtin_command(tmp[0]);
	free_pptr((void **)tmp);
	return (result);
}
