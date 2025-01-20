/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentense_preprocess.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:58:19 by takwak            #+#    #+#             */
/*   Updated: 2025/01/20 18:38:51 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_list	*sentense_preprocess(char *str)
{
	t_list	*head;
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
	head = NULL;
	while (str[i])
	{
		split_point = find_metachar(str, i);
		if (split_point)
		{
			data = make_data(str, SENTENSE, i, ft_strchr(&str[i], split_point) - str);
			ft_lstadd_back(&head, ft_lstnew((void *)data));
			data = split_piece(str, i, split_point);
			ft_lstadd_back(&head, ft_lstnew((void *)data));
			i = data->end + 1;
		}
		else
		{
			data = make_data(str, SENTENSE, i, ft_strchr(&str[i], '\0') - str);
			ft_lstadd_back(&head, ft_lstnew((void *)data));
			break ;
		}
	}
	return (head);
}
