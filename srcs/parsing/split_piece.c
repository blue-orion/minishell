/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:24:16 by takwak            #+#    #+#             */
/*   Updated: 2025/01/21 22:16:38 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	make_parenthesis_data(char *str, int start, int *start_idx, int *end_idx)
{
	int	i;
	int	parenthesis_cnt;

	i = start;
	parenthesis_cnt = 0;
	while (str[i])
	{
		if (str[i] == '(')
		{
			if (parenthesis_cnt == 0)
				*start_idx = i + 1;
			parenthesis_cnt++;
		}
		if (str[i] == ')')
		{
			parenthesis_cnt--;
			if (parenthesis_cnt == 0)
			{
				*end_idx = i;
				break ;
			}
		}
		i++;
	}
}

t_data	*split_piece(char *str, int start, int split_point)
{
	t_data	*data;
	int		start_idx;
	int		end_idx;
	int		type;

	if (split_point == SINGLE_QUOTE)
	{
		type = SINGLE_QUOTE;
		start_idx = ft_strchr(&str[start], '\'') + 1 - str;
		end_idx = ft_strchr(str + start_idx + 1, '\'') - str;
	}
	if (split_point == DOUBLE_QUOTE)
	{
		type = DOUBLE_QUOTE;
		start_idx = ft_strchr(&str[start], '\"') + 1 - str;
		end_idx = ft_strchr(str + start_idx + 1, '\"') - str;
	}
	if (split_point == PARENTHESIS)
	{
		type = PARENTHESIS;
		make_parenthesis_data(str, start, &start_idx, &end_idx);
	}
	return (make_data(str, type, start_idx, end_idx));
}
