/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_sentense_to_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:58:19 by takwak            #+#    #+#             */
/*   Updated: 2025/02/11 19:39:10 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int		add_sentense(t_node *root, char *s, int start, int split_point);
int		add_splited(t_node *root, char *s, int start, int split_point);
int		add_rest(t_node *root, char *s, int start);

t_node	*split_sentense_to_list(t_node *root, char *str)
{
	int		move;
	int		start_idx;
	int		split_point;

	move = 0;
	start_idx = 0;
	split_point = find_metachar(str, start_idx);
	while (split_point)
	{
		add_sentense(root, str, start_idx, split_point);
		start_idx = add_splited(root, str, start_idx, split_point) + 1;
		split_point = find_metachar(str, start_idx);
		if (!start_idx)
		{
			treeclear(root);
			free(str);
			write(2, "Invalid Input\n", 14);
			return (NULL);
		}
	}
	add_rest(root, str, start_idx);
	free(str);
	return (root);
}

int	add_sentense(t_node *root, char *s, int start, int split_point)
{
	t_data	*new_data;
	t_list	*new_lst;
	int		end;

	end = ft_strchr(&s[start], split_point) - s;
	new_data = make_data(s, SENTENSE, start, end);
	if (!new_data)
		error_exit("malloc failed in split sentense");
	if (new_data->type != EMPTY)
	{
		new_lst = ft_lstnew((void *)new_data);
		if (!new_lst)
			error_exit("malloc failed in split sentense");
		ft_lstadd_back(&root->head, new_lst);
	}
	else
		free_data(new_data);
	return (0);
}

int	add_splited(t_node *root, char *s, int start, int split_point)
{
	t_data	*new_data;
	t_list	*new_lst;
	int		flag;
	int		move;

	flag = 0;
	new_data = split_piece(s, start, split_point, &flag);
	if (flag)
		return (-1);
	if (!new_data)
		error_exit("malloc failed in split sentense");
	if (new_data->type != EMPTY)
	{
		new_lst = ft_lstnew((void *)new_data);
		if (!new_lst)
			error_exit("malloc failed in split sentense");
		ft_lstadd_back(&root->head, new_lst);
	}
	else
	{
		move = new_data->end;
		free_data(new_data);
		return (move);
	}
	return (new_data->end);
}

int	add_rest(t_node *root, char *s, int start)
{
	t_data	*new_data;
	t_list	*new_lst;

	new_data = make_data(s + start, SENTENSE, 0, ft_strlen(s + start));
	if (!new_data)
		error_exit("malloc failed in split sentense");
	if (new_data->type != EMPTY)
	{
		new_lst = ft_lstnew((void *)new_data);
		if (!new_lst)
			error_exit("malloc failed in split sentense");
		ft_lstadd_back(&root->head, new_lst);
	}
	else
		free_data(new_data);
	return (0);
}
