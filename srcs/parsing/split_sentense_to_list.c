/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_sentense_to_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:58:19 by takwak            #+#    #+#             */
/*   Updated: 2025/02/02 20:23:06 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

char	*preprocess_string(char *src)
{
	char	*res;

	subsitute_tab(src);
	res = remove_invalid_quote(res, src);
	free(src);
	if (!res)
		error_exit("command preprocess failed");
	src = res;
	res = ft_strtrim(src, " ");
	free(src);
	if (!res)
		error_exit("command preprocess failed");
	return (res);
}

int	add_sentense(t_node *root, char *s, int start, int split_point)
{
	t_data	*new_data;
	t_list	*new_lst;

	new_data = make_data(s, SENTENSE,
			start, ft_strchr(&s[start], split_point) - s);
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
		free(new_data);
	return (0);
}

int	add_splited(t_node *root, char *s, int start, int split_point)
{
	t_data	*new_data;
	t_list	*new_lst;

	new_data = split_piece(s, start, split_point);
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
		free(new_data);
		return (0);
	}
	return (new_data->end);
}

int	add_rest(t_node *root, char *s, int start)
{
	t_data	*new_data;
	t_list	*new_lst;

	new_data = make_data(s, SENTENSE,
			start, ft_strchr(&s[start], '\0') - s);
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
		free(new_data);
	return (0);
}

t_node	*split_sentense_to_list(t_node *root, char *str)
{
	int		start_idx;
	int		split_point;
	int		move;

	str = preprocess_string(str);
	start_idx = 0;
	move = 0;
	split_point = find_metachar(str, start_idx);
	while (split_point)
	{
		add_sentense(root, str, start_idx, split_point);
		move = add_splited(root, str, start_idx, split_point);
		start_idx = move + 1;
		split_point = find_metachar(str, start_idx);
	}
	add_rest(root, str, start_idx);
	return (root);
}
