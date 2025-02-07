/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_node_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:46:38 by takwak            #+#    #+#             */
/*   Updated: 2025/02/07 16:46:38 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	separator_node(t_node *parent, t_list *cur, int separator, int idx[2])
{
	t_data	*new_data;
	t_data	*data;
	int		start;
	int		end;

	start = idx[LEFT];
	end = idx[RIGHT];
	data = (t_data *)cur->content;
	new_data = make_data(data->text, separator, start, end);
	if (!new_data)
		error_exit("parse node failed");
	parent->head = NULL;
	parent->type = SEPARATOR;
	ft_lstdelone(cur, free_data);
	make_list_and_addback(&parent->head, new_data);
}

void	head_list_left_node(t_node *cur_node, t_list *cur_lst, int left)
{
	t_data	*cur_data;
	t_data	*new_data;
	t_list	*new_lst;

	cur_data = (t_data *)cur_lst->content;
	new_data = make_data(cur_data->text, CMD, 0, left);
	if (!new_data)
		error_exit("parse node failed");
	if (new_data->type != EMPTY)
	{
		new_lst = ft_lstnew((void *)new_data);
		if (!new_lst)
			error_exit("parse node failed");
		cur_node->left_child = new_node(new_lst);
		if (!cur_node->left_child)
			error_exit("parse node failed");
	}
	else
		free_data(new_data);
}

void	head_list_right_node(t_node *cur_node, t_list *cur_lst, int right)
{
	t_data		*cur_data;
	t_data		*new_data;
	t_list		*new_lst;
	const int	end = ft_strlen(((t_data *)cur_lst->content)->text + right);

	cur_data = (t_data *)cur_lst->content;
	new_data = make_data(cur_data->text + right, SENTENSE, 0, end);
	if (!new_data)
		error_exit("parse node failed");
	if (new_data->type != EMPTY)
	{
		new_lst = ft_lstnew((void *)new_data);
		if (!new_lst)
			error_exit("parse node failed");
		new_lst->next = cur_lst->next;
		cur_node->right_child = new_node(new_lst);
		if (!cur_node->right_child)
			error_exit("parse node failed");
	}
	else
	{
		free_data(new_data);
		cur_node->right_child = new_node(cur_lst->next);
		cur_lst->next = NULL;
	}
}

void	no_head_left_node(t_node *parent, t_list *head, t_list *cur, int left)
{
	t_list	*past_lst;
	t_data	*cur_data;
	t_data	*new_data;
	t_list	*new_lst;

	cur_data = (t_data *)cur->content;
	past_lst = head;
	while (past_lst->next != cur)
		past_lst = past_lst->next;
	past_lst->next = NULL;
	new_data = make_data(cur_data->text, CMD, 0, left);
	if (!new_data)
		error_exit("parse node failed");
	if (new_data->type != EMPTY)
	{
		new_lst = ft_lstnew((void *)new_data);
		if (!new_lst)
			error_exit("parse node failed");
		past_lst->next = new_lst;
	}
	else
		free_data(new_data);
	parent->left_child = new_node(head);
	if (!parent->left_child)
		error_exit("parse node failed");
}

void	no_head_right_node(t_node *parent, t_list *cur, int right)
{
	t_data	*cur_data;
	t_data	*new_data;
	t_list	*new_lst;
	int		end;

	cur_data = (t_data *)cur->content;
	end = ft_strlen(cur_data->text + right);
	new_data = make_data(cur_data->text + right, SENTENSE, 0, end);
	if (!new_data)
		error_exit("parse node failed");
	if (new_data->type != EMPTY)
	{
		new_lst = ft_lstnew((void *)new_data);
		if (!new_lst)
			error_exit("parse node failed");
		new_lst->next = cur->next;
		parent->right_child = new_node(new_lst);
	}
	else
	{
		free_data(new_data);
		parent->right_child = new_node(cur->next);
	}
}
