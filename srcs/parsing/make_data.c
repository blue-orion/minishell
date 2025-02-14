/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:25:29 by takwak            #+#    #+#             */
/*   Updated: 2025/02/14 20:14:53 by takwak           ###   ########.fr       */
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

char	*make_text(t_data *new, char *str)
{
	char	*past;

	new->text = ft_substr(str, new->start, new->end - new->start);
	if (!new->text)
		return (NULL);
	if (new->type != SINGLE_QUOTE && new->type != DOUBLE_QUOTE)
	{
		if (is_empty_str(new->text))
			new->type = EMPTY;
		else
		{
			past = new->text;
			new->text = ft_strtrim(past, " ");
			free(past);
			if (!new->text)
				return (NULL);
		}
	}
	return (new->text);
}

t_data	*make_data(char *str, int type, int start, int end)
{
	t_data	*new;
	char	*past;

	new = (t_data *)malloc(sizeof(t_data));
	if (!new)
		return (NULL);
	new->type = type;
	new->invalid[0] = 0;
	new->invalid[1] = 0;
	new->start = start;
	new->end = end;
	new->text = make_text(new, str);
	if (!new->text)
		return (free(new), NULL);
	return (new);
}
