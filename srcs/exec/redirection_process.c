/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:32:20 by takwak            #+#    #+#             */
/*   Updated: 2025/02/24 17:29:43 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

int	in_redirection(t_list *file);
int	out_redirection(t_list *file);
int	append_redirection(t_list *file);

int	redirection_process(t_cmd *info, t_node *cur_node)
{
	int	status;

	if (!cur_node)
		return (0);
	if (cur_node->type == REDIRECTS)
	{
		redirection_process(info, cur_node->left_child);
		redirection_process(info, cur_node->right_child);
		return (0);
	}
	if (!cur_node->head->next)
	{
		ft_putendl_fd("minishell: syntax error", 2);
		info->exit_status = 2;
		return (2);
	}
	if (cur_node->type == IN)
		status = in_redirection(cur_node->head->next);
	if (cur_node->type == OUT)
		status = out_redirection(cur_node->head->next);
	if (cur_node->type == HERE_DOC)
		status = here_doc_redirection(info, cur_node->head->next);
	if (cur_node->type == APPEND)
		status = append_redirection(cur_node->head->next);
	return (status);
}

int	in_redirection(t_list *file)
{
	t_data	*data;
	int		fd;

	data = (t_data *)file->content;
	if (access(data->text, F_OK))
	{
		put_error_msg(data->text, NULL, NO_FILE_OR_DIR);
		return (1);
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
