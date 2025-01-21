/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_separator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:36:27 by takwak            #+#    #+#             */
/*   Updated: 2025/01/21 20:16:07 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	which_separator(char *str, int separator)
{
	int	idx;

	if (separator == AND)
		idx = ft_strnstr(str, "&&", ft_strlen(str)) - str;
	if (separator == OR)
		idx = ft_strnstr(str, "||", ft_strlen(str)) - str;
	if (separator == PIPE)
		idx = ft_strnstr(str, "|", ft_strlen(str)) - str;
	if (separator == AMPER)
		idx = ft_strnstr(str, "&", ft_strlen(str)) - str;
	if (separator == SEMI)
		idx = ft_strnstr(str, ";", ft_strlen(str)) - str;
	return (idx);
}
