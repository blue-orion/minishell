/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:13:54 by takwak            #+#    #+#             */
/*   Updated: 2025/01/21 17:56:35 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

#include "libft.h"

typedef struct s_data
{
	int		type;
	char	*text;
	int		start;
	int		end;
}	t_data;

typedef struct s_node
{
	t_list			*head;
	struct s_node	*left_child;
	struct s_node	*right_child;
}	t_node;

int		add_node_left(t_node *parent, t_node *child);
int		add_node_right(t_node *parent, t_node *child);
t_node	*make_new_node(t_list *list);
void	print_tree(t_node *root);

#endif
