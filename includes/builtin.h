/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:20:44 by takwak            #+#    #+#             */
/*   Updated: 2025/02/05 22:20:44 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

int	ft_cd(char **cmd);
int	ft_echo(char **cmd);
int	ft_env(char **cmd);
int	ft_exit(char **cmd);
int	ft_export(char **cmd);
int	ft_pwd(char **cmd);
int	ft_unset(char **cmd);

#endif
