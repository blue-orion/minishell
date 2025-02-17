/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:49:31 by takwak            #+#    #+#             */
/*   Updated: 2025/02/17 23:09:37 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"
#include <readline/readline.h>
#include <fcntl.h>
#include <termios.h>

int	here_doc_redirection(t_cmd *info, t_list *eof_list)
{
	t_data	*data;
	int		fd;
	char	*input;
	char	*past;
	int		save_fd[2];

	save_fd[0] = dup(0);
	save_fd[1] = dup(1);
	dup2(info->stdfd[INPUT], 0);
	dup2(info->stdfd[OUTPUT], 1);
	data = (t_data *)eof_list->content;
	fd = open("tmp.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (info->input_buf[ft_strlen(info->input_buf) - 1] != '\n')
		info->input_buf = ft_strjoin(info->input_buf, "\n");
	while (*info->cmd_buf)
	{
		if (!ft_strncmp(*info->cmd_buf, data->text, ft_strlen(data->text)))
		{
			input = add_newline(*info->cmd_buf);
			write(fd, input, ft_strlen(input));
			free(input);
			info->cmd_buf++;
			close(fd);
			fd = open("tmp.txt", O_RDONLY);
			if (dup2(fd, 0))
				error_exit("dup2 failed while here_doc");
			close(fd);
			return (0);
		}
		else
		{
			input = add_newline(*info->cmd_buf);
			write(fd, input, ft_strlen(input));
			free(input);
		}
		info->cmd_buf++;
	}
	input = readline("> ");
	while (input && ft_strncmp(input, data->text, ft_strlen(data->text)))
	{
		input = add_newline(input);
		write(fd, input, ft_strlen(input));
		free(input);
		input = readline("> ");
	}
	input = add_newline(input);
	write(fd, input, ft_strlen(input));
	free(input);
	close(fd);
	fd = open("tmp.txt", O_RDONLY);
	if (dup2(fd, 0))
		error_exit("dup2 failed while here_doc");
	close(fd);
	dup2(save_fd[1], 1);
	close(save_fd[1]);
	close(save_fd[0]);
	return (0);
}
