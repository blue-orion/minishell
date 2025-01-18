/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:21:33 by takwak            #+#    #+#             */
/*   Updated: 2025/01/18 16:04:33 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*unit_block(char *str, char unit)
{
	char	*res;
	char	*end;
	int		idx;

	end = ft_strchr(str, unit);
	idx = end - str;
	str[idx] = '\0';
	res = ft_strdup(str + 1);
	if (!res)
		return (NULL);
	free(str);
	return (res);
}
