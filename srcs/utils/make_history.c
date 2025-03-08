/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 00:19:02 by takwak            #+#    #+#             */
/*   Updated: 2025/02/18 00:19:02 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"
#include <fcntl.h>

char	*make_history(char *cmd)
{
	int		fd;
	char	*line;
	char	*tmp;

	tmp = ft_strdup(cmd);
	if (access("history.txt", F_OK))
		return (tmp);
	fd = open("history.txt", O_RDONLY);
	if (fd < 0)
		error_exit("open error");
	if (!tmp)
		error_exit("malloc failed");
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_join_free(tmp, line);
		if (!tmp)
			error_exit("malloc failed");
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	unlink("history.txt");
	return (tmp);
}
