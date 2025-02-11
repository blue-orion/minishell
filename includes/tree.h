/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:13:54 by takwak            #+#    #+#             */
/*   Updated: 2025/02/01 19:40:21 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include "struct.h"

int		add_node_left(t_node *parent, t_node *child);
int		add_node_right(t_node *parent, t_node *child);
t_node	*new_node(t_list *list);
void	print_tree(t_node *root);
void	*treeclear(t_node *root);

#endif
