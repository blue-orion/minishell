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
	if (!ft_strncmp(str, "<<", 2))
		return (HERE_DOC);
	if (!ft_strncmp(str, ">>", 2))
		return (APPEND);
	if (!ft_strncmp(str, "<", 1))
		return (IN);
	if (!ft_strncmp(str, ">", 1))
		return (OUT);
	return (0);
}
