/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:24:16 by takwak            #+#    #+#             */
/*   Updated: 2025/02/14 20:16:06 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	make_parenthesis(char *str, long start, long *start_idx, long *end_idx)
{
	int	i;
	int	parenthesis_cnt;

	i = start - 1;
	parenthesis_cnt = 0;
	while (str[++i])
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
	}
	if (parenthesis_cnt != 0)
		*end_idx = -1;
}

t_data	*split_piece(char *str, int start, int split_point, int *flag)
{
	long	start_idx;
	long	end_idx;
	int		type;
	t_data	*new_data;
	int		invalid[2];

	invalid[0] = 0;
	invalid[1] = 0;
	if (split_point == SINGLE_QUOTE)
	{
		type = SINGLE_QUOTE;
		start_idx = ft_strchr(&str[start], '\'') + 1 - str;
		if (start_idx > 2 && str[start_idx - 2] && !is_metachar(str[start_idx - 2]))
			invalid[0] = 1;
		end_idx = ft_strchr(str + start_idx, '\'') - str;
		if (str[end_idx + 1] && !is_metachar(str[end_idx + 1]))
			invalid[1] = 1;
	}
	if (split_point == DOUBLE_QUOTE)
	{
		type = DOUBLE_QUOTE;
		start_idx = ft_strchr(&str[start], '\"') + 1 - str;
		if (start_idx > 2 && str[start_idx - 2] && !is_metachar(str[start_idx - 2]))
			invalid[0] = 1;
		end_idx = ft_strchr(str + start_idx, '\"') - str;
		if (str[end_idx + 1] && !is_metachar(str[end_idx + 1]))
			invalid[1] = 1;
	}
	if (split_point == PARENTHESIS)
	{
		type = PARENTHESIS;
		make_parenthesis(str, start, &start_idx, &end_idx);
	}
	if (start_idx < 0 || end_idx < 0)
		return ((*flag)++, NULL);
	new_data = make_data(str, type, start_idx, end_idx);
	if (!new_data)
		error_exit("malloc failed");
	new_data->invalid[0] = invalid[0];
	new_data->invalid[1] = invalid[1];
	return (new_data);
}
