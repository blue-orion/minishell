/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treeclear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:36:21 by takwak            #+#    #+#             */
/*   Updated: 2025/02/14 21:53:21 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tree.h"
#include "../../includes/utils.h"

void	*treeclear(t_node *root)
{
	if (!root)
		return (NULL);
	treeclear(root->left_child);
	treeclear(root->right_child);
	ft_lstclear(&root->head, free_data);
	free(root);
	root = NULL;
	return (NULL);
}
