/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 01:29:04 by takwak            #+#    #+#             */
/*   Updated: 2025/02/15 14:11:44 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_cmd	info;
	char	*input;
	char	*tmp;

	signal_setup();
	init_info(&info, env);
	while (1)
	{
		info.parent = NULL;
		info.pipe_flag = 0;
		dup2(info.stdfd[INPUT], 0);
		dup2(info.stdfd[OUTPUT], 1);
		input = readline("minishell> ");
		if (!input)
			break ;
		info.input_buf = ft_strdup(input);
		tmp = malloc(sizeof(char) * (ft_strlen(input) + 2));
		ft_strlcpy(tmp, input, ft_strlen(input) + 1);
		tmp[ft_strlen(input)] = '\n';
		tmp[ft_strlen(input) + 1] = '\0';
		info.cmd_buf = ft_split(tmp, '\n');
		free(tmp);
		while (*info.cmd_buf)
		{
			input = preprocess_string(&info, *info.cmd_buf);
			info.cmd_buf++;
			info.root = parsing(input);
			if (!info.root)
				continue ;
			printf("\n\n");
			print_tree(info.root);
			exec_tree_node(&info, info.root);
			treeclear(info.root);
		}
		add_history(info.input_buf);
		free(info.input_buf);
		rl_on_new_line();
	}
	return (0);
}
