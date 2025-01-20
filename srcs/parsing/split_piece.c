/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:24:16 by takwak            #+#    #+#             */
/*   Updated: 2025/01/19 20:58:23 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_data	*split_piece(char *str, int start, int split_point)
{
	t_data	*data;
	char	*start_adr;
	int		end;
	int		type;

	if (split_point == SINGLE_QUOTE)
	{
		type = SINGLE_QUOTE;
		start_adr = ft_strchr(&str[start], '\'') + 1;
		end = ft_strchr(start_adr + 1, '\'') - str;
	}
	if (split_point == DOUBLE_QUOTE)
	{
		type = DOUBLE_QUOTE;
		start_adr = ft_strchr(&str[start], '\"') + 1;
		end = ft_strchr(start_adr + 1, '\"') - str;
	}
	if (split_point == PARENTHESIS)
	{
		type = PARENTHESIS;
		start_adr = ft_strchr(&str[start], '(') + 1;
		end = ft_strchr(start_adr + 1, ')') - str;
	}
	return (make_data(str, type, start_adr - str, end));
}
