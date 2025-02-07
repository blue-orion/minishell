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
# include "builtin.h"
# include <unistd.h>
# include <sys/wait.h>

# define CMD_NOT_FOUNT "command not found"
# define PERMISSION_DENIED "Permission denied"
# define NO_FILE_OR_DIR "No such file or directory"
# define INPUT 1
# define OUTPUT 0

typedef struct s_cmd
{
	t_node		*root;
	char		**cmd;
	char		**path;
	pid_t		pid[2];
	int			pipe_fd[2];
	int			stdfd[2];
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
int	is_builtin_node(t_node *root);
int	is_builtin_command(char *cmd);
int	exec_command(t_cmd *info, t_node *cur_node);
void	pipe_separator_process(t_cmd *info, t_node *cur_node);
void	logical_separator_process(t_cmd *info, t_node *cur_node);
void	simple_separator_process(t_cmd *info, t_node *cur_node);
int	separator_process(t_cmd *info, t_node *cur_node);
int	call_builtin_ft(char **cmd);
void	execve_fail(char *error_msg, int status);
int	call_execve(char **cmd, char **path);
#endif
