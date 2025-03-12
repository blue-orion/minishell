/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:21:15 by takwak            #+#    #+#             */
/*   Updated: 2025/03/12 17:29:31 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "tree.h"
# include "utils.h"
# include "define.h"

t_node	*parsing(char *str, t_cmd *info);

char	*ft_getenv(char *name, char **envp);
char	*preprocess_string(char *src);
int		is_metachar(char c);

void	subsitute_tab_to_space(char *str);
char	*unit_block(char *str, char unit);
t_node	*split_sentense_to_list(t_node *root, char *str);

int		is_redirection(char *str);
int		is_separator(char *str);
char	find_metachar(char *str, int start);
int		find_separator(char	*text);
t_list	*find_redirection(t_list *head);
int		find_token(t_list *lst, int to_find);

t_list	*move_to_token(t_list *cur, int to_move);

t_data	*split_piece(char *str, int start, int split_point, int *flag);
void	split_redirects_node(t_node *parent);
t_data	*make_data(char *str, int type, int start, int end);

int		make_parsing_tree(t_node *cur_node);
void	*free_pptr(void **pptr);
void	subsitute_tab(char *str);
void	print_list(t_list *head);
int		which_separator(char *str, int separator);
int		which_redirection(char *str, int *redirection);
void	parse_node(t_node *parent, t_list *head, t_list *cur, int separator);
/*void	split_cmd_node(t_node *parent);*/
void	split_cmd_node(t_node *parent, t_cmd *info);
t_list	*make_redirects_list(t_list *head);
t_list	*make_redirection_list(t_list **head);
t_list	*make_simple_cmd_list(t_list *head);
int		make_list_and_addback(t_list **head, t_data *new_data);
int		make_list_and_addleft(t_node *parent, t_data *new_data);
int		is_type(int dst_type, t_list *src);
void	head_list_left_node(t_node *cur_node, t_list *cur_lst, int left);
void	head_list_right_node(t_node *cur_node, t_list *cur_lst, int right);
void	no_head_left_node(t_node *parent, t_list *head, t_list *cur, int left);
void	no_head_right_node(t_node *parent, t_list *cur, int right);
void	separator_node(t_node *parent, t_list *cur, int separator, int idx[2]);
void	interpret_wildcard(t_list **head, t_cmd *info);
char	*interpret_env(char *text, t_cmd *info);
void	remove_invalid_quote(t_list *head);
void	interpret_env_all(t_list *head, t_cmd *info);
#endif
