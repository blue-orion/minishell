/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_seperate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 00:31:00 by takwak            #+#    #+#             */
/*   Updated: 2025/01/18 16:32:17 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/libft.h"

int	is_separator(char *str)
{
	if (ft_strncmp(str, "|", 2))
		return (PIPE);
	if (ft_strncmp(str, "&&", 3))
		return (AND);
	if (ft_strncmp(str, "||", 3))
		return (OR);
	if (ft_strncmp(str, "&", 2))
		return (AMPER);
	if (ft_strncmp(str, ";", 2))
		return (APPEND);
	return (0);
}
