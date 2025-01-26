/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:54:46 by takwak            #+#    #+#             */
/*   Updated: 2025/01/27 03:33:16 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "libft.h"

void	print_list(t_list *head);
int		skip_space(char *s);
void	*free_pptr(void **pptr);
void	free_data(void *content);
#endif
