/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:07:13 by takwak            #+#    #+#             */
/*   Updated: 2025/03/05 20:51:38 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "parsing.h"
# include "builtin.h"
# include "define.h"
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>

typedef struct	s_wildcard
{
	char	*dir_path;
	char	*match;
	char	*sub_pattern;
	char	*prefix_match;
	char	*suffix_match;
	int		dir_flag;
	int		prefix_flag;
}	t_wildcard;

void	init_info(t_cmd *info, char **envp);
int		exec_tree_node(t_cmd *info, t_node *cur_node);
int		make_child_process(t_cmd *info);
char	**list_to_str(t_cmd *info, t_list **head);
void	redirect_pipe(t_cmd *info, t_node *cur_node);
int		parenthesis_process(t_cmd *info, t_node *cur_node);
int		is_builtin_node(t_cmd *info, t_node *root);
int		is_builtin_command(char *cmd);
int		exec_command(t_cmd *info, t_node *cur_node);
void	pipe_separator_process(t_cmd *info, t_node *cur_node);
void	logical_separator_process(t_cmd *info, t_node *cur_node);
void	simple_separator_process(t_cmd *info, t_node *cur_node);
void	separator_process(t_cmd *info, t_node *cur_node);
void	execve_fail(t_cmd *info, char *cmd, char *error_msg, int status);
int		call_builtin_ft(char **cmd, t_cmd *info);
void	call_execve(char **cmd, t_cmd *info);
int		redirection_process(t_cmd *info, t_node *cur_node);
int		command_execve_process(t_cmd *info, t_node *cur_node);
int		here_doc_redirection(t_cmd *info, t_list *eof_list);
int		match_prefix(char *file, char *prefix);
int		match_suffix(char *file, char *suffix);
char	*interpret_env(char *text, t_cmd *info);
void	set_exit_status(t_cmd *info, int status);
void	wait_child(t_cmd *info, pid_t child_pid);
void	fork_child(t_cmd *info, t_node *child_node);
void	remove_invalid_quote(t_list *head);
void	end_process(t_cmd *info);

//Wildcard
void	push_before_asterisk(t_list *head, char	**split_text);
int		include_asterisk(char *str);
void	interpret_wildcard(t_list **head, t_cmd *info);
char	*find_dir_path(char *text);
char	*extract_match(char *text);
int	is_valid_entry(struct dirent *dp, t_wildcard *wc_info);
char	*get_wildcard_token(char **strs);
t_wildcard	extract_wildcard_info(t_wildcard *wc_info, char *wildcard_token);
void	push_entry(t_list **head, char *entry, t_wildcard *wc_info);
#endif
