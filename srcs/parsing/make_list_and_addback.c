/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list_and_addback.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:05:46 by takwak            #+#    #+#             */
/*   Updated: 2025/02/25 22:18:38 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"
#include "../../includes/struct.h"

void	make_list_and_addback(t_list **head, t_data *new_data)
{
	t_list	*new_lst;

	new_lst = ft_lstnew((void *)new_data);
	if (!new_lst)
		error_exit("failed malloc in make_list_and_addback");
	ft_lstadd_back(head, new_lst);
}
