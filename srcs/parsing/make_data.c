/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:25:29 by takwak            #+#    #+#             */
/*   Updated: 2025/02/03 21:55:45 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	is_empty_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

t_data	*make_data(char *str, int type, int start, int end)
{
	t_data	*new;
	char	*past;

	new = (t_data *)malloc(sizeof(t_data));
	if (!new)
		return (NULL);
	new->type = type;
	new->text = ft_substr(str, start, end - start);
	new->start = start;
	new->end = end;
	if (!new->text)
		return (free(new), NULL);
	if (type != SINGLE_QUOTE && type != DOUBLE_QUOTE)
	{
		if (is_empty_str(new->text))
		{
			new->type = EMPTY;
			return (new);
		}
		past = new->text;
		new->text = ft_strtrim(past, " ");
		if (!new->text)
			return (free(past), free(new), NULL);
		free(past);
	}
	return (new);
}
