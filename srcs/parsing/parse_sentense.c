/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sentense.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:55:13 by takwak            #+#    #+#             */
/*   Updated: 2025/01/17 22:58:13 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/libft.h"

int	parse_sentense(char	*str)
{
	t_list	**head;
	t_data	*data;

	str = sentense_preprocess(str);
	if (!str)
		return (-1);
	t_data = (t_data *)malloc(sizeof(t_data));
	if (find_quote())
		data = quoted_data();
	if (find_parenthesis())
		data = parenthesis_data();
	preprocess_quote(str);//따옴표가 있으면 따옴표 처리
	preprocess_parenthesis(str);//괄호가 있으면 괄호 처리
	//SEPARATOR를 기준으로 CMD 구분
	//이후 SEPARAOTR 처리
}
