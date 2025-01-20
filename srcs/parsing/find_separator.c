/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_separator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:48:44 by takwak            #+#    #+#             */
/*   Updated: 2025/01/20 20:48:44 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	find_separator(char	*text)
{
	if (ft_strnstr(text, " | ", 4))
		return (PIPE);
	if (ft_strnstr(text, " && ", 5))
		return (AND);
	if (ft_strnstr(text, " || ", 5))
		return (OR);
	if (ft_strnstr(text, " & ", 4))
		return (AMPER);
	if (ft_strnstr(text, " ; ", 4))
		return (SEMI);
	return (0);
}
