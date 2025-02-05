/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_simple_cmd_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeonsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:38:29 by takwak            #+#    #+#             */
/*   Updated: 2025/02/05 16:21:33 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#define START 0
#define END 1

void	extract_simple_cmd(t_list **dst, t_list *cmd, t_list *src, int *flag);
void	simple_cmd_node(t_list **dst, t_list *src, t_list *cmd, int index[2]);
int		next_redirection(char *str);

t_list	*make_simple_cmd_list(t_list *head)
{
	t_list	*cur_lst;
	t_list	*res_lst;
	t_list	*past_lst;
	t_data	*data;
	int		flag;

	res_lst = NULL;
	cur_lst = head;
	while (find_redirection(cur_lst))
	{
		cur_lst = move_to_token(cur_lst, CMD);
		extract_simple_cmd(&res_lst, cur_lst, head, &flag);
		past_lst = cur_lst;
		cur_lst = cur_lst->next;
		if (flag)
			ft_lstdelone(past_lst, free_data);
	}
	return (res_lst);
}

void	extract_simple_cmd(t_list **dst, t_list *cmd, t_list *src, int *flag)
{
	int				i;
	int				redirect;
	int				index[2];
	const t_data	*data = (t_data *)cmd->content;

	i = 0;
	*flag = 0;
	index[START] = 0;
	while (data->text[i])
	{
		redirect = is_redirection(data->text + i);
		if (redirect)
		{
			index[END] = i++;
			simple_cmd_node(dst, src, cmd, index);
			if (*dst == src)
				*flag = 1;
			if (redirect == HERE_DOC || redirect == APPEND)
				i++;
			i += next_redirection(data->text + i);
			index[START] = i;
		}
		else
			i++;
	}
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
		free_data(new_data);
		past_lst = src;
		while (past_lst->next && past_lst->next != cmd)
			past_lst = past_lst->next;
		if (past_lst->next == cmd)
		{
			((t_data *)src->content)->type = SIMPLE_CMD;
			*dst = src;
			past_lst->next = NULL;
		}
	}
	else
		if (make_list_and_addback(dst, new_data))
			error_exit("failed malloc in making simple_cmd_node");
}

int	next_redirection(char *str)
{
	int	i;

	i = skip_space(str);
	while (str[i] && str[i] != ' ' && !is_redirection(str + i))
		i++;
	return (i);
}
