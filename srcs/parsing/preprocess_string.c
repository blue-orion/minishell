/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:38:18 by takwak            #+#    #+#             */
/*   Updated: 2025/02/25 21:44:17 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

char	*preprocess_string(t_cmd *info, char *src)
{
	char	*res;

	subsitute_tab(src);
	res = ft_strtrim(src, " ");
	if (!res)
		error_exit("command preprocess failed");
	return (res);
}
