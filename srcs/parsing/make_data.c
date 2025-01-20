/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:25:29 by takwak            #+#    #+#             */
/*   Updated: 2025/01/20 18:30:48 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_data	*make_data(char *str, int type, int start, int end)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	if (!new)
		return (NULL);
	new->type = type;
	new->text = ft_substr(str, start, end - start);
	new->start = start;
	new->end = end;
	return (new);
}
