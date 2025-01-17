/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentense_preprocess.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:58:19 by takwak            #+#    #+#             */
/*   Updated: 2025/01/18 00:30:52 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"
#include "../../includes/libft.h"

t_node	**sentense_preprocess(char	*str)
{
	t_node	**tokens;
	char	*piece;
	int		i;
	int		move;

	i = 0;
	while (str[i])
	{
		if (ft_isblank(str[i]))
			move = 1;
		if (str[i] == SINGLE_QUOTE)
			piece = unit_block(&str[i], SINGLE_QUOTE, &move);
		if (str[i] == DOUBLE_QUOTE)
			piece = unit_block(&str[i], DOUBLE_QUOTE, &move);
		if (str[i] == PARENTHESIS)
			piece = unit_block(&str[i], PARENTHESIS, &move);
		if (isseparator(str))
			piece = isseparator(str);

	}
}
