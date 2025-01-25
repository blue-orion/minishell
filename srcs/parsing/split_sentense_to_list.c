/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_sentense_to_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:58:19 by takwak            #+#    #+#             */
/*   Updated: 2025/01/21 22:21:10 by takwak           ###   ########.fr       */
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
		return (NULL);
	src = res;
	res = ft_strtrim(src, " ");
	free(src);
	if (!res)
		return (NULL);
	return (res);
}

int	add_sentense(t_node *root, char *s, int start, int split_point)
{
	t_data	*new_data;
	t_list	*new_lst;

	new_data = make_data(s, SENTENSE,
			start, ft_strchr(&s[start], split_point) - s);
	if (!new_data)
	{
		free(s);
		return (-1);
	}
	if (new_data->type != EMPTY)
	{
		new_lst = ft_lstnew((void *)new_data);
		if (!new_lst)
		{
			free(s);
			free(new_data);
			return (-1);
		}
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
	{
		free(s);
		return (-1);
	}
	if (new_data->type != EMPTY)
	{
		new_lst = ft_lstnew((void *)new_data);
		if (!new_lst)
		{
			free(s);
			free(new_data);
			return (-1);
		}
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
	{
		free(s);
		return (-1);
	}
	if (new_data->type != EMPTY)
	{
		new_lst = ft_lstnew((void *)new_data);
		if (!new_lst)
		{
			free(s);
			free(new_data);
			return (-1);
		}
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
	if (!str)
		return (perror("failed malloc"), NULL);
	start_idx = 0;
	move = 0;
	split_point = find_metachar(str, start_idx);
	while (split_point)
	{
		move = add_sentense(root, str, start_idx, split_point);
		if (move)
			return (NULL);
		move = add_splited(root, str, start_idx, split_point);
		if (!move)
			return (NULL);
		start_idx = move + 1;
		split_point = find_metachar(str, start_idx);
	}
	if (add_rest(root, str, start_idx))
		return (NULL);
	return (root);
}
