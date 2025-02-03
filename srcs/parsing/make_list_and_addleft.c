/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list_and_addleft.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:45:19 by takwak            #+#    #+#             */
/*   Updated: 2025/02/02 20:53:12 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tree.h"

t_node	*make_new_node_from(t_data *new_data)
{
	t_list	*new_lst;
	t_node	*new;

	new_lst = ft_lstnew((void *)new_data);
	if (!new_lst)
		return (NULL);
	new = new_node(new_lst);
	if (!new)
	{
		free(new_lst);
		return (NULL);
	}
	return (new);
}
