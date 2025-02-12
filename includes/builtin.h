/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:20:44 by takwak            #+#    #+#             */
/*   Updated: 2025/02/12 18:35:57 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "struct.h"

int	ft_cd(char **cmd);
int	ft_echo(char **cmd);
int	ft_env(char **cmd, char **envp);
int	ft_exit(char **cmd);
int	ft_export(char **cmd, t_cmd *info);
int	ft_pwd(char **cmd);
int	ft_unset(char **cmd, t_cmd *info);
int	getsize(char **cmd);
int	check_name(char *str);

#endif
