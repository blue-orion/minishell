/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:10:15 by takwak            #+#    #+#             */
/*   Updated: 2025/02/19 20:10:53 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_join_free(char *s1, char *s2)
{
	char	*past;

	past = s1;
	s1 = ft_strjoin(s1, s2);
	free(past);
	return (s1);
}
