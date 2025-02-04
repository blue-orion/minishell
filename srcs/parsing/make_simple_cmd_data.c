/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_simple_cmd_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeonsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:38:29 by takwak            #+#    #+#             */
/*   Updated: 2025/02/05 00:42:56 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#define START 0
#define END 1

void	extract_simple_cmd(t_list **dst, t_list *cmd, t_list *src);
void	simple_cmd_node(t_list **dst, t_list *src, t_list *cmd, int index[2]);
int		next_redirection(char *str);

t_list	*make_simple_cmd_list(t_list *head)
{
	t_list	*cur_lst;
	t_list	*res_lst;
	t_data	*data;
	int		flag;

	res_lst = NULL;
	cur_lst = head;
	while (find_redirection(cur_lst))
	{
		cur_lst = move_to_token(cur_lst, CMD);
		extract_simple_cmd(&res_lst, cur_lst, head);
		cur_lst = cur_lst->next;
	}
	return (res_lst);
}

void	simple_cmd_node(t_list **dst, t_list *src, t_list *cmd, int index[2])
{
	t_data	*data;
	t_data	*new_data;
	t_list	*past_lst;

	data = (t_data *)cmd->content;
	new_data = make_data(data->text, SIMPLE_CMD, index[START], index[END]);
	if (!new_data)
		error_exit("failed malloc in making simple_cmd_node");
	if (new_data->type == EMPTY)
	{
		past_lst = src;
		while (past_lst->next && past_lst->next != cmd)
			past_lst = past_lst->next;
		if (past_lst->next == cmd)
		{
			*dst = src;
			past_lst->next = NULL;
		}
	}
	else
		if (make_list_and_addback(dst, new_data))
			error_exit("failed malloc in making simple_cmd_node");
}

void	extract_simple_cmd(t_list **dst, t_list *cmd, t_list *src)
{
	int		i;
	int		redirect;
	int		index[2];
	t_data	*data;

	i = 0;
	index[START] = 0;
	data = (t_data *)cmd->content;
	while (data->text[i])
	{
		redirect = is_redirection(data->text + i);
		if (redirect)
		{
			index[END] = i++;
			simple_cmd_node(dst, src, cmd, index);
			if (redirect == HERE_DOC || redirect == APPEND)
				i++;
			i += next_redirection(data->text + i);
			index[START] = i;
		}
		else
			i++;
	}
}

int	next_redirection(char *str)
{
	int	i;

	i = skip_space(str);
	while (str[i] && str[i] != ' ' && !is_redirection(str + i))
		i++;
	return (i);
}
