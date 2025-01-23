/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:41:35 by takwak            #+#    #+#             */
/*   Updated: 2025/01/23 15:41:35 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_list	*move_to_token(t_list *cur, int to_move)
{
	t_data	*data;

	data = (t_data *)cur->content;
	while (data->type != to_move)
	{
		cur = cur->next;
		data = (t_data *)cur->content;
	}
	return (cur);
}
