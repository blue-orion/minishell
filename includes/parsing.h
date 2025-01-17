/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:21:15 by takwak            #+#    #+#             */
/*   Updated: 2025/01/18 00:31:56 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

enum e_unit
{
	SENTENSE = 1,
	SINGLE_QUOTE = '\'',
	DOUBLE_QUOTE = '\"',
	PARENTHESIS = '(',
	SEPARATOR,
	REDIRECTS,
	CMD,
	SIMPLE_CMD,
	FILE_NAME
};

typedef struct s_node
{
	int				type;
	char			*content;
	struct s_node	*left_child;
	struct s_node	*right_child;
}	t_node;

int		add_node_left(t_node *parent, t_node *child);
int		add_node_right(t_node *parent, t_node *child);
t_node	*make_new_node(int type, char *content);
char	*unit_block(char *str, char quote, int *move);
#endif
