/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:38:18 by takwak            #+#    #+#             */
/*   Updated: 2025/02/12 18:57:42 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

char	*preprocess_string(t_cmd *info, char *src)
{
	char	*res;

	subsitute_tab(src);
	res = interpret_env(src, info->envp);
	free(src);
	src = res;
	res = remove_invalid_quote(src);
	free(src);
	if (!res)
		error_exit("command preprocess failed");
	if (!*res)
		return (res);
	src = res;
	res = ft_strtrim(src, " ");
	free(src);
	if (!res)
		error_exit("command preprocess failed");
	return (res);
}

