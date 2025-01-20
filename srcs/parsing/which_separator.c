/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_separator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:36:27 by takwak            #+#    #+#             */
/*   Updated: 2025/01/20 21:36:27 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	which_separator(char *str, int separator)
{
	int	idx;

	if (separator == PIPE)
		idx = ft_strnstr(str, " | ", 4) - str;
	if (separator == AND)
		idx = ft_strnstr(str, " && ", 5) - str;
	if (separator == OR)
		idx = ft_strnstr(str, " || ", 5) - str;
	if (separator == AMPER)
		idx = ft_strnstr(str, " & ", 4) - str;
	if (separator == SEMI)
		idx = ft_strnstr(str, " ; ", 4) - str;
	return (idx);
}
