/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:54:46 by takwak            #+#    #+#             */
/*   Updated: 2025/02/10 15:37:54 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "libft.h"

void	print_list(t_list *head);
void	print_type(int type);
int		skip_space(char *s);
void	*free_pptr(void **pptr);
void	free_data(void *content);
void	error_exit(char *msg);
void	put_error_msg(char *cmd, char *arg, char *error_msg);
char	**copy_envp(char **envp);
#endif
