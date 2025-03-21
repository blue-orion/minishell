/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:24:16 by takwak            #+#    #+#             */
/*   Updated: 2025/03/21 19:50:42 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	find_parenthesis(char *str, long start, long *start_idx, long *end_idx)
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

t_data	*get_quote_data(char *str, int start, int type)
{
	long	start_idx;
	long	end_idx;
	t_data	*new_data;

	if (type == SINGLE_QUOTE)
	{
		start_idx = ft_strchr(&str[start], '\'') + 1 - str;
		end_idx = ft_strchr(str + start_idx, '\'') - str;
	}
	if (type == DOUBLE_QUOTE)
	{
		start_idx = ft_strchr(&str[start], '\"') + 1 - str;
		end_idx = ft_strchr(str + start_idx, '\"') - str;
	}
	if (start_idx < 0 || end_idx < 0)
		return (NULL);
	new_data = make_data(str, type, start_idx, end_idx);
	if (!new_data)
		error_exit("malloc failed");
	if (start_idx > 2 && str[start_idx - 2] && !is_metachar(str[start_idx - 2]))
		new_data->invalid[0] = 1;
	if (str[end_idx + 1] && !is_metachar(str[end_idx + 1]))
		new_data->invalid[1] = 1;
	return (new_data);
}

t_data	*split_piece(char *str, int start, int split_point)
{
	long	start_idx;
	long	end_idx;
	t_data	*new_data;

	if (split_point == SINGLE_QUOTE || split_point == DOUBLE_QUOTE)
		new_data = get_quote_data(str, start, split_point);
	if (split_point == PARENTHESIS)
	{
		find_parenthesis(str, start, &start_idx, &end_idx);
		new_data = make_data(str, PARENTHESIS, start_idx, end_idx);
		if (!new_data)
			error_exit("malloc failed");
	}
	if (!new_data)
		return (NULL);
	return (new_data);
}
