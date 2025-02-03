/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treeclear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:36:21 by takwak            #+#    #+#             */
/*   Updated: 2025/02/03 20:46:06 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tree.h"
#include "../../includes/utils.h"

void	*treeclear(t_node *root)
{
	t_node	*cur;

	if (!root)
		return (NULL);
	treeclear(root->left_child);
	treeclear(root->right_child);
	cur = root;
	ft_lstclear(&cur->head, free_data);
	free(root);
	return (NULL);
}
