/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:36:14 by takwak            #+#    #+#             */
/*   Updated: 2025/03/28 20:52:26 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "parsing.h"
# include "libft.h"
# include "exec.h"
# include "define.h"
# include "builtin.h"
# include "struct.h"
# include "mini_signal.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>

void	exec_input(t_cmd *info, t_node *cur_node);
void	end_minishell(t_cmd *info);
#endif
