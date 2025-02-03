/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:21:15 by takwak            #+#    #+#             */
/*   Updated: 2025/02/03 21:35:19 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "tree.h"
# include "utils.h"

enum e_unit
{
	SENTENSE = 1,
	SINGLE_QUOTE = '\'',
	DOUBLE_QUOTE = '\"',
	PARENTHESIS = '(',
	SEPARATOR = 2,
	CMD = 3,
	REDIRECTS = 4,
	SIMPLE_CMD = 5,
	FILE_NAME = 6,
	EMPTY
};

enum e_separator
{
	PIPE = 8,
	AND,
	OR,
	AMPER,
	SEMI
};

enum e_redirect
{
	IN = 13,
	OUT,
	HERE_DOC,
	APPEND
};

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
char	*remove_invalid_quote(char *src);
void	print_list(t_list *head);
int		which_separator(char *str, int separator);
int		which_redirection(char *str, int *redirection);
void	parse_node(t_node *parent, t_list *head, t_list *cur, int separator);
void	split_cmd_node(t_node *parent);
t_list	*make_redirects_list(t_list *head);
t_list	*make_redirection_list(t_list **head);
t_list	*make_simple_cmd_list(t_list *head);
int		make_list_and_addback(t_list **head, t_data *new_data);
int		make_list_and_addleft(t_node *parent, t_data *new_data);
int		is_type(int dst_type, t_list *src);
#endif
