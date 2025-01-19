/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentense_preprocess.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:58:19 by takwak            #+#    #+#             */
/*   Updated: 2025/01/19 20:37:05 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/libft.h"

int	get_split_size(char **splited)
{
	int	size;

	size = 0;
	while (splited[size])
		size++;
	return (size);
}

char	*sentense_preprocess(char *str)
{
	t_list	*head;
	t_data	*data;
	char	*past;
	int		split_point;
	char	*res;

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
		if (!split_point)
			break ;
		data = split_piece(str, i, split_point);
		ft_lstadd_back(&head, ft_lstnew((void *)data));
		i = data->end + 1;
	}
	while (head)
	{
		printf("%s\n", ((t_data *)head->content)->text);
		head = head->next;
	}
	// preprocess_quote(str);//따옴표가 있으면 따옴표 처리
	// preprocess_parenthesis(str);//괄호가 있으면 괄호 처리
	//SEPARATOR를 기준으로 CMD 구분
	//이후 SEPARAOTR 처리
}
