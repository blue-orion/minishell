/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:32:46 by takwak            #+#    #+#             */
/*   Updated: 2025/01/18 14:53:29 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/libft.h"

t_node	*parsing(char *str)
{
	t_node	*root;
	t_list	**head;

	parse_sentense(str);
	// root = make_new_node(SENTENSE, str);
	// if (!root)
	// 	return (NULL);
}
