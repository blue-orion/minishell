/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:21:33 by takwak            #+#    #+#             */
/*   Updated: 2025/01/18 00:23:45 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*unit_block(char *str, char unit, int *move)
{
	char	*end;
	int		idx;

	end = ft_strchr(str, unit);
	*move = end - str;
	str[*move] = '\0';
	(*move)++;
	return (str + 1);
}
