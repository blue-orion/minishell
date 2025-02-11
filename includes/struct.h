/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:36:20 by takwak            #+#    #+#             */
/*   Updated: 2025/02/11 17:36:20 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_data
{
	int		type;
	char	*text;
	int		start;
	int		end;
}	t_data;

typedef struct s_node
{
	t_list			*head;
	int				type;
	struct s_node	*left_child;
	struct s_node	*right_child;
}	t_node;

typedef struct s_cmd
{
	t_node		*root;
	char		**cmd;
	char		**path;
	char		**envp;
	pid_t		pid[2];
	int			pipe_fd[2];
	int			stdfd[2];
	int			pipe_flag;
	t_node		*parent;
	sigset_t	set;
	int			exit_status;
}	t_cmd;

#endif
