/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentense_preprocess.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:58:19 by takwak            #+#    #+#             */
/*   Updated: 2025/01/21 22:21:10 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_node	*sentense_preprocess(t_node *root, char *str)
{
	t_list	*list;
	t_data	*data;
	char	*past;
	int		split_point;

	//탭은 공백으로 치환
	subsitute_tab(str);
	//유효하지 않은 따옴표 제거
	past = str;
	str = remove_invalid_quote(str);
	if (!str)
		return (NULL);
	free(past);
	//앞 뒤 공백 제거
	past = str;
	str = ft_strtrim(past, " ");
	if (!str)
		return (NULL);
	free(past);
	
	int i;
	i = 0;
	while (str[i])
	{
		split_point = find_metachar(str, i);
		if (split_point)
		{
			data = make_data(str, SENTENSE, i, ft_strchr(&str[i], split_point) - str);
			if (data->type != EMPTY)
				ft_lstadd_back(&root->head, ft_lstnew((void *)data));
			data = split_piece(str, i, split_point);
			if (data->type != EMPTY)
				ft_lstadd_back(&root->head, ft_lstnew((void *)data));
			i = data->end + 1;
		}
		else
		{
			data = make_data(str, SENTENSE, i, ft_strchr(&str[i], '\0') - str);
			ft_lstadd_back(&root->head, ft_lstnew((void *)data));
			break ;
		}
	}
	return (root);
}
