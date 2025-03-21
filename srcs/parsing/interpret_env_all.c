/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_env_all.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:54:52 by takwak            #+#    #+#             */
/*   Updated: 2025/03/21 19:55:01 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	interpret_env_all(t_list *head, t_cmd *info)
{
	t_data	*data;
	char	*past;

	while (head)
	{
		data = (t_data *)head->content;
		if (data->type == SINGLE_QUOTE || !ft_strchr(data->text, '$'))
		{
			head = head->next;
			continue ;
		}
		past = data->text;
		data->text = interpret_env(data->text, info);
		free(past);
		head = head->next;
	}
}
