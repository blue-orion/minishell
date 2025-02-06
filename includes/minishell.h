/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:36:14 by takwak            #+#    #+#             */
/*   Updated: 2025/02/06 15:21:37 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "parsing.h"
# include "libft.h"
# include "exec.h"
# include "builtin.h"
# include "mini_signal.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_cmd
{
	t_node		*root;
	char		**cmd;
	pid_t		pid[2];
	int			pipe_fd[2];
	sigset_t	set;
}	t_cmd;

t_node	*parsing(char *str);
void	exec_parsing_tree(t_cmd *info, t_node *parent);
#endif
