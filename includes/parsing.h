/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:21:15 by takwak            #+#    #+#             */
/*   Updated: 2025/01/20 18:31:09 by takwak           ###   ########.fr       */
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
	FILE_NAME
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

typedef struct s_data
{
	int		type;
	char	*text;
	int		start;
	int		end;
}	t_data;

void	subsitute_tab_to_space(char *str);
char	*unit_block(char *str, char unit);
int		is_redirection(char *str);
int		is_separator(char *str);
t_list	*sentense_preprocess(char *str);

char	find_metachar(char *str, int start);
t_data	*split_piece(char *str, int start, int split_point);
t_data	*make_data(char *str, int type, int start, int end);

void	*free_pptr(void **pptr);
void	subsitute_tab(char *str);
char	*remove_invalid_quote(char *src);
int		parse_sentense(t_list *head);
void	print_list(t_list *head);
int		find_separator(char	*text);
int	which_separator(char *str, int separator);
#endif
