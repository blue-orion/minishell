/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:21:15 by takwak            #+#    #+#             */
/*   Updated: 2025/01/21 23:36:56 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "tree.h"
# include "libft.h"

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
	FILE_NAME,
	EMPTY
};

enum e_separator
{
	PIPE = 1,
	AND,
	OR,
	AMPER,
	SEMI
};

enum e_redirect
{
	IN = 1,
	OUT,
	HERE_DOC,
	APPEND
};
int		is_metachar(char c);

void	subsitute_tab_to_space(char *str);
char	*unit_block(char *str, char unit);
int		is_redirection(char *str);
int		is_separator(char *str);
t_node	*sentense_preprocess(t_node *root, char *str);

char	find_metachar(char *str, int start);
t_data	*split_piece(char *str, int start, int split_point);
t_data	*make_data(char *str, int type, int start, int end);

t_node	*parse_sentense(t_node *cur_node);
void	*free_pptr(void **pptr);
void	subsitute_tab(char *str);
char	*remove_invalid_quote(char *src);
void	print_list(t_list *head);
int		find_separator(char	*text);
int	which_separator(char *str, int separator);
t_node	*parse_node(t_node *cur_node, t_list *past, t_list *cur, int separator);
#endif
