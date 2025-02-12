/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:41:32 by takwak            #+#    #+#             */
/*   Updated: 2025/02/12 17:53:09 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtin.h"

int	ft_pwd(char **cmd)
{
	char	*pwd;

	pwd = getcwd(pwd, 4096);
	write(1, pwd, ft_strlen(pwd));
	return (0);
}
