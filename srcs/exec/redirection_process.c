/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:32:20 by takwak            #+#    #+#             */
/*   Updated: 2025/02/07 23:32:20 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

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
		here_doc_redirection(cur_node->head->next);
	if (cur_node->type == APPEND)
		append_redirection(cur_node->head->next);
}

int	in_redirection(t_list *file)
{
	t_data	*data;

	data = (t_data *)file;
	if (access(data->text, F_OK))
	{
		execve_fail(NO_FILE_OR_DIR, 1);
		return ;
	}

}
