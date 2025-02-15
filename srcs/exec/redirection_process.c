/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:32:20 by takwak            #+#    #+#             */
/*   Updated: 2025/02/15 14:03:55 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	in_redirection(t_list *file);
int	out_redirection(t_list *file);
int	append_redirection(t_list *file);
int	here_doc_redirection(t_cmd *info, t_list *eof);

void	redirection_process(t_cmd *info, t_node *cur_node)
{
	if (!cur_node)
		return ;
	if (cur_node->type == REDIRECTS)
	{
		redirection_process(info, cur_node->left_child);
		redirection_process(info, cur_node->right_child);
		return ;
	}
	if (cur_node->type == IN)
		in_redirection(cur_node->head->next);
	if (cur_node->type == OUT)
		out_redirection(cur_node->head->next);
	if (cur_node->type == HERE_DOC)
		here_doc_redirection(info, cur_node->head->next);
	if (cur_node->type == APPEND)
		append_redirection(cur_node->head->next);
}

int	in_redirection(t_list *file)
{
	t_data	*data;
	int		fd;

	data = (t_data *)file->content;
	if (access(data->text, F_OK))
	{
		execve_fail(NO_FILE_OR_DIR, 1);
		return (-1);
	}
	fd = open(data->text, O_RDONLY);
	if (fd < 0)
		error_exit("open error");
	if (dup2(fd, 0) < 0)
		error_exit("dup2 error");
	return (0);
}

int	out_redirection(t_list *file)
{
	t_data	*data;
	int		fd;

	data = (t_data *)file->content;
	fd = open(data->text, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		error_exit("open error");
	if (dup2(fd, 1) < 0)
		error_exit("dup2 error");
	return (0);
}

int	here_doc_redirection(t_cmd *info, t_list *eof)
{
	t_data	*data;
	char	*input;
	int		fd[2];
	int		len;
	char	*past;

	data = (t_data *)eof->content;
	len = ft_strlen(data->text);
	pipe(fd);
	while (*info->cmd_buf)
	{
		if (!ft_strncmp(*info->cmd_buf, data->text, len))
		{
			info->cmd_buf++;
			close(fd[1]);
			if (dup2(fd[0], 0))
				return (-1);
			close(fd[0]);
			return (0);	
		}
		else
		{
			input = ft_strjoin(*info->cmd_buf, "\n");
			write(fd[1], input, ft_strlen(input));
			// free(*info->cmd_buf);
		}
		info->cmd_buf++;
	}
	input = readline("> ");
	past = input;
	input = ft_strjoin(input, "\n");
	free(past);
	past = info->input_buf;
	info->input_buf = ft_strjoin(info->input_buf, "\n");
	free(past);
	past = info->input_buf;
	info->input_buf = ft_strjoin(info->input_buf, input);
	free(past);
	while (ft_strncmp(input, data->text, len))
	{
		write(fd[1], input, ft_strlen(input));
		free(input);
		input = readline("> ");
		past = input;
		input = ft_strjoin(input, "\n");
		free(past);
		past = info->input_buf;
		info->input_buf = ft_strjoin(info->input_buf, input);
		free(past);
	}
	close(fd[1]);
	if (dup2(fd[0], 0))
		return (-1);
	close(fd[0]);
	free(input);
	return (0);
}

int	append_redirection(t_list *file)
{
	t_data	*data;
	int		fd;

	data = (t_data *)file->content;
	fd = open(data->text, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		error_exit("open error");
	if (dup2(fd, 1) < 0)
		error_exit("dup2 error");
	return (0);
}
