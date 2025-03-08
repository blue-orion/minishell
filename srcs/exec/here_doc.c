/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:49:31 by takwak            #+#    #+#             */
/*   Updated: 2025/03/08 22:02:09 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"
#include <readline/readline.h>
#include <fcntl.h>

void	init_redirection(int *save_fd, int *std_fd);
void	write_input_to_tmp(int fd, char *input);
int		put_extra_input(t_cmd *info, char *eof);
void	get_here_doc_input(char *eof);

int	here_doc_redirection(t_cmd *info, t_list *eof_list)
{
	int		fd;
	char	*eof;
	int		save_fd[2];
	int		end_flag;

	end_flag = 0;
	init_redirection(save_fd, info->stdfd);
	if (info->input_buf[ft_strlen(info->input_buf) - 1] != '\n')
		info->input_buf = ft_join_free(info->input_buf, "\n");
	eof = ((t_data *)eof_list->content)->text;
	end_flag = put_extra_input(info, eof);
	if (!end_flag)
		get_here_doc_input(eof);
	fd = open("tmp.txt", O_RDONLY);
	if (fd < 0)
		error_exit("open error");
	if (dup2(fd, 0) < 0)
		error_exit("dup2 failed while here_doc");
	if (dup2(save_fd[1], 1) < 0)
		error_exit("dup2 failed while here_doc");
	close(fd);
	unlink("tmp.txt");
	close(save_fd[1]);
	close(save_fd[0]);
	return (0);
}

void	init_redirection(int *save_fd, int *std_fd)
{
	save_fd[0] = dup(0);
	save_fd[1] = dup(1);
	if (save_fd[0] < 0 || save_fd[1] < 0)
		error_exit("dup error in init");
	if (dup2(std_fd[INPUT], 0) < 0)
		error_exit("dup error in init");
	if (dup2(std_fd[OUTPUT], 1) < 0)
		error_exit("dup error in init");
}

int	put_extra_input(t_cmd *info, char *eof)
{
	int		i;
	int		fd1;
	int		fd2;

	fd1 = open("tmp.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	fd2 = open("history.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd1 < 0 || fd2 < 0)
		error_exit("open error");
	while (info->cmd_buf[info->buf_idx])
	{
		if (!ft_strncmp(info->cmd_buf[info->buf_idx], eof, ft_strlen(eof) + 1))
		{
			write_input_to_tmp(fd2, info->cmd_buf[info->buf_idx++]);
			close(fd1);
			close(fd2);
			return (1);
		}
		write_input_to_tmp(fd1, info->cmd_buf[info->buf_idx]);
		write_input_to_tmp(fd2, info->cmd_buf[info->buf_idx]);
		info->buf_idx++;
	}
	close(fd1);
	close(fd2);
	return (0);
}

void	get_here_doc_input(char *eof)
{
	char	*input;
	int		fd1;
	int		fd2;

	fd1 = open("tmp.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	fd2 = open("history.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd1 < 0 || fd2 < 0)
		error_exit("open error");
	input = readline("> ");
	while (input && ft_strncmp(input, eof, ft_strlen(eof) + 1))
	{
		write_input_to_tmp(fd1, input);
		write_input_to_tmp(fd2, input);
		free(input);
		input = readline("> ");
	}
	if (input)
		write_input_to_tmp(fd2, input);
	close(fd1);
	close(fd2);
}

void	write_input_to_tmp(int fd, char *input)
{
	char	*input_nl;

	input_nl = ft_strjoin(input, "\n");
	write(fd, input_nl, ft_strlen(input_nl));
	free(input_nl);
}
