/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:50:01 by takwak            #+#    #+#             */
/*   Updated: 2025/03/11 15:50:22 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "../../includes/utils.h"

int	is_dir(char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf))
		error_exit("stat failed");
	if (S_ISDIR(statbuf.st_mode))
		return (1);
	return (0);
}
