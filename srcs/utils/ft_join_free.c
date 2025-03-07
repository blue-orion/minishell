/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:10:15 by takwak            #+#    #+#             */
/*   Updated: 2025/03/04 23:47:47 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

char	*ft_join_free(char *s1, char *s2)
{
	char	*past;

	past = s1;
	s1 = ft_strjoin(s1, s2);
	if (!s1)
		error_exit("malloc failed in ft_join_free");
	free(past);
	return (s1);
}
