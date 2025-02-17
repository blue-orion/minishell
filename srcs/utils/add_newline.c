/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_newline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 00:16:33 by takwak            #+#    #+#             */
/*   Updated: 2025/02/18 00:16:33 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

char	*add_newline(char *str)
{
	int		len;
	char	*nlstr;

	len = ft_strlen(str);
	nlstr = (char *)malloc(sizeof(char) * (len + 2));
	if (!nlstr)
		error_exit("malloc failed");
	ft_strlcpy(nlstr, str, len + 1);
	nlstr[len] = '\n';
	nlstr[len + 1] = '\0';
	free(str);
	return (nlstr);
}
