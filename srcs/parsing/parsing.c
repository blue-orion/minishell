/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:32:46 by takwak            #+#    #+#             */
/*   Updated: 2025/01/17 22:55:04 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parsing.h"

t_node	*parsing(char *str)
{
	t_node	*root;

	root = make_new_node(root, SENTENSE, str);
	if (!root)
		return (NULL);
	parse_sentense(root);
}
