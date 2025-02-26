/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:07:13 by takwak            #+#    #+#             */
/*   Updated: 2025/02/24 19:15:15 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "parsing.h"
# include "builtin.h"
# include "struct.h"

# define CMD_NOT_FOUND "command not found"
# define PERMISSION_DENIED "Permission denied"
# define NO_FILE_OR_DIR "No such file or directory"
# define IS_DIR "Is a directory"
# define INPUT 1
# define OUTPUT 0

void	init_info(t_cmd *info, char **envp);
int		exec_tree_node(t_cmd *info, t_node *cur_node);
int		make_child_process(t_cmd *info);
char	**list_to_str(t_cmd *info, t_list *head);
void	redirect_pipe(t_cmd *info, t_node *cur_node);
int		parenthesis_process(t_cmd *info, t_node *cur_node);
int		is_builtin_node(t_cmd *info, t_node *root);
int		is_builtin_command(char *cmd);
int		exec_command(t_cmd *info, t_node *cur_node);
void	pipe_separator_process(t_cmd *info, t_node *cur_node);
void	logical_separator_process(t_cmd *info, t_node *cur_node);
void	simple_separator_process(t_cmd *info, t_node *cur_node);
void	separator_process(t_cmd *info, t_node *cur_node);
void	execve_fail(char *cmd, char *error_msg, int status);
int		call_builtin_ft(char **cmd, t_cmd *info);
void	call_execve(char **cmd, t_cmd *info);
int		redirection_process(t_cmd *info, t_node *cur_node);
int		command_execve_process(t_cmd *info, t_node *cur_node);
int		here_doc_redirection(t_cmd *info, t_list *eof_list);
int		interpret_wildcard(t_cmd *info, t_data *data);
int		match_prefix(char *file, char *prefix);
int		match_suffix(char *file, char *suffix);
char	*interpret_env(char *text, t_cmd *info);
void	set_exit_status(t_cmd *info, int status);
void	wait_child(t_cmd *info, pid_t child_pid);
void	fork_child(t_cmd *info, t_node *child_node);
#endif
