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

t_data	*make_single_quote_data(t_data *data, char *str, int start)
{
	char	*start_adr;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->type = SINGLE_QUOTE;
	start_adr = ft_strchr(&str[start], '\'') + 1;
	data->start = start_adr - str;
	data->end = ft_strchr(start_adr + 1, '\'') - str;
	data->text = ft_substr(str, data->start, data->end - data->start);
	return (data);
}

t_data	*make_double_quote_data(t_data *data, char *str, int start)
{
	char	*start_adr;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->type = DOUBLE_QUOTE;
	start_adr = ft_strchr(&str[start], '\"') + 1;
	data->start = start_adr - str;
	data->end = ft_strchr(start_adr + 1, '\"') - str;
	data->text = ft_substr(str, data->start, data->end - data->start);
	return (data);
}

t_data	*make_parenthesis_data(t_data *data, char *str, int start)
{
	char	*start_adr;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->type = PARENTHESIS;
	start_adr = ft_strchr(&str[start], '(') + 1;
	data->start = start_adr - str;
	data->end = ft_strchr(start_adr + 1, ')') - str;
	data->text = ft_substr(str, data->start, data->end - data->start);
	return (data);
}

t_data	*split_piece(char *str, int start, int split_point)
{
	t_data	*data;

	if (split_point == SINGLE_QUOTE)
		data = make_single_quote_data(data, str, start);
	if (split_point == DOUBLE_QUOTE)
		data = make_double_quote_data(data, str, start);
	if (split_point == PARENTHESIS)
		data = make_parenthesis_data(data, str, start);
	if (!data)
		return (NULL);
	return (data);
}
