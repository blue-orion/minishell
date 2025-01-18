/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:32:05 by takwak            #+#    #+#             */
/*   Updated: 2025/01/18 16:32:15 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/libft.h"

int	is_redirection(char *str)
{
	if (ft_strncmp(str, "<", 2))
		return (IN);
	if (ft_strncmp(str, ">", 2))
		return (OUT);
	if (ft_strncmp(str, "<<", 3))
		return (HERE_DOC);
	if (ft_strncmp(str, ">>", 3))
		return (APPEND);
	return (0);
}
