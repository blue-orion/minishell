/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:54:46 by takwak            #+#    #+#             */
/*   Updated: 2025/03/11 15:50:28 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "struct.h"
# include "libft.h"

void	print_list(t_list *head);
void	print_type_a(int type);
void	print_type_b(int type);

int		skip_space(char *s);
void	*free_pptr(void **pptr);
void	free_data(void *content);
void	error_exit(char *msg);
void	put_error_msg(char *cmd, char *arg, char *error_msg);
char	**copy_envp(char **envp);
char	*add_newline(char *str);
char	*make_history(char *cmd);
char	*ft_join_free(char *s1, char *s2);
int		is_empty_str(char *str);
void	dup_env(char **dst, char **src);
char	*get_name(char *str);
int		get_name_index(char *name, char **envp);
char	*ft_getenv(char *name, char **envp);
int		get_pptr_size(void **arr);
void	ft_free_resource(t_cmd *info);
int		is_dir(char *path);
#endif
