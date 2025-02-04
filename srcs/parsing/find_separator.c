/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_separator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:48:44 by takwak            #+#    #+#             */
/*   Updated: 2025/02/04 22:26:44 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "limits.h"

int	find_separator(char	*text)
{
	int	i;

	i = 0;
	while (text[i])
	{
		if (text[i] == '|')
		{
			if (text[i + 1] == '|')
				return (OR);
			return (PIPE);
		}
		if (text[i] == '&')
		{
			if (text[i + 1] == '&')
				return (AND);
			return (AMPER);
		}
		if (text[i] == ';')
			return (SEMI);
		i++;
	}
	return (0);
}
