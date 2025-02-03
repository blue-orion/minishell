/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:55:08 by takwak            #+#    #+#             */
/*   Updated: 2025/02/03 21:05:23 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	head_list_left_node(t_node *cur_node, t_list *cur_lst, int left);
void	head_list_right_node(t_node *cur_node, t_list *cur_lst, int right);
void	no_head_left_node(t_node *parent, t_list *head, t_list *cur, int left);
void	no_head_right_node(t_node *parent, t_list *cur, int right);

void	parse_node(t_node *parent, t_list *head, t_list *cur, int separator)
{
	t_data	*data;
	t_data	*new_data;
	int		left;
	int		right;

	data = (t_data *)cur->content;
	left = which_separator(data->text, separator);
	right = left + 1;
	if (separator == AND || separator == OR)
		right++;
	if (head == cur)
	{
		head_list_left_node(parent, cur, left);
		head_list_right_node(parent, cur, right);
	}
	else
	{
		no_head_left_node(parent, head, cur, left);
		no_head_right_node(parent, cur, right);
	}
	new_data = make_data(data->text, separator, left, right);
	if (!new_data)
		error_exit("parse node failed");
	parent->head = NULL;
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
	t_data	*cur_data;
	t_data	*new_data;
	t_list	*new_lst;

	cur_data = (t_data *)cur_lst->content;
	new_data = make_data(cur_data->text, SENTENSE, right, cur_data->end);
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

	cur_data = (t_data *)cur->content;
	new_data = make_data(cur_data->text, SENTENSE, right, cur_data->end);
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
