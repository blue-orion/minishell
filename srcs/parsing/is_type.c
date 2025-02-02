/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_is.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:24:22 by takwak            #+#    #+#             */
/*   Updated: 2025/02/02 21:25:59 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tree.h"

int	is_type(int dst_type, t_list *src)
{
	t_data	*data;

	data = (t_data *)src->content;
	if (data->type == dst_type)
		return (1);
	return (0);
}
