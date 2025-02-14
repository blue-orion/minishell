/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list_and_addback.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:05:46 by takwak            #+#    #+#             */
/*   Updated: 2025/02/14 22:06:48 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"

int	make_list_and_addback(t_list **head, t_data *new_data)
{
	t_list	*new_lst;

	new_lst = ft_lstnew((void *)new_data);
	if (!new_lst)
		return (-1);
	ft_lstadd_back(head, new_lst);
	return (0);
}
