/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:07:13 by takwak            #+#    #+#             */
/*   Updated: 2025/02/06 21:22:52 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "parsing.h"
# include <unistd.h>
# include <sys/wait.h>

typedef struct s_cmd
{
	t_node		*root;
	char		**cmd;
	pid_t		pid[2];
	int			pipe_fd[2];
	int			pipe_flag;
	t_node		*parent;
	sigset_t	set;
	int			exit_status;
}	t_cmd;

void	init_info(t_cmd *info);
void	exec_tree_node(t_cmd *info, t_node *parent);
int	make_child_process(t_cmd *info);
char	**list_to_str(t_list *head);
void	redirect_pipe(t_cmd *info, t_node *cur_node);
int	parenthesis_process(t_cmd *info, t_node *cur_node);
void	pipe_separator_process(t_cmd *info, t_node *cur_node);
#endif
