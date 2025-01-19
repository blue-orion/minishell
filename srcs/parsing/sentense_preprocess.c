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
	t_list	**head;
	t_data	*data;
	char	*past;
	int		split_point;
	char	*res;

	subsitute_tab(str); //탭 공백으로 치환 따옴표 유효한지 체크
	past = str;
	str = ft_strtrim(past, " ");
	free(past);
	split_point = find_metachar(str);
	data = split_piece(str, split_point);
	if (find_quote())
		data = quoted_data();
	if (find_parenthesis())
		data = parenthesis_data();
	preprocess_quote(str);//따옴표가 있으면 따옴표 처리
	preprocess_parenthesis(str);//괄호가 있으면 괄호 처리
	//SEPARATOR를 기준으로 CMD 구분
	//이후 SEPARAOTR 처리
}
