/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:21:15 by takwak            #+#    #+#             */
/*   Updated: 2025/01/18 17:41:24 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "tree.h"

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
}	t_data;

void	subsitute_tab(char *str);
char	*unit_block(char *str, char unit);
int		is_redirection(char *str);
int		is_separator(char *str);
void	*free_pptr(void **pptr);
#endif
