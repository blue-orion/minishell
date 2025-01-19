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
#include "../../includes/libft.h"

t_data	*make_single_quote_data(t_data *data, char *str)
{
	char	*start;
	char	*end;

	data = (t_data *)malloc(sizeof(t_data));
	start = ft_strchr(str, '\'') + 1;
	end = ft_strchr(start + 1, '\'');
	data->text = ft_substr(str, start - str, end - start);
	data->type = SINGLE_QUOTE;
	return (data);
}

t_data	*make_double_quote_data(t_data *data, char *str)
{
	char	*start;
	char	*end;

	data = (t_data *)malloc(sizeof(t_data));
	start = ft_strchr(str, '\"') + 1;
	end = ft_strchr(start + 1, '\"');
	data->text = ft_substr(str, start - str, end - start);
	data->type = DOUBLE_QUOTE;
	return (data);
}

t_data	*make_parenthesis_data(t_data *data, char *str)
{
	char	*start;
	char	*end;

	data = (t_data *)malloc(sizeof(t_data));
	start = ft_strchr(str, '(') + 1;
	end = ft_strchr(start + 1, ')');
	data->text = ft_substr(str, start - str, end - start);
	data->type = PARENTHESIS;
	return (data);
}

t_data	*make_cmd_data(t_data *data, char *str)
{
	char	*start;
	char	*end;

	data = (t_data *)malloc(sizeof(t_data));
	data->text = ft_substr(str, start - str, end - start);
	data->type = PARENTHESIS;
	return (data);
}

t_data	*split_piece(int split_point, char *str)
{
	t_data	*data;

	if (split_point == SINGLE_QUOTE)
		data = make_single_quote_data(data, str);
	if (split_point == DOUBLE_QUOTE)
		data = make_double_quote_data(data, str);
	if (split_point == PARENTHESIS)
		data = make_parenthesis_data(data, str);
	if (split_point == ' ' || !split_point)
		data = make_cmd_data(data, str);
	return (data);
}
