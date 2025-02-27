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

	if (access("tmp.txt", F_OK))
		return (cmd);
	fd = open("tmp.txt", O_RDONLY);
	if (fd < 0)
		error_exit("open error");
	line = get_next_line(fd);
	while (line)
	{
		cmd = ft_join_free(cmd, line);
		if (!cmd)
			error_exit("malloc failed");
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	unlink("tmp.txt");
	return (cmd);
}
