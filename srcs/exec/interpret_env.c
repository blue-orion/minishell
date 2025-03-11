/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:27:04 by takwak            #+#    #+#             */
/*   Updated: 2025/03/08 23:55:54 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec.h"

int		extract_name(char *name, char *text);
char	*get_env_value(char *value, char *name, t_cmd *info);
void	copy_remaining_data(char *res, char *text, int last_name_idx);

char	*interpret_env(char *text, t_cmd *info)
{
	char	*res;
	char	name[4096];
	char	value[4096];
	char	*last_name_end_adr;
	char	*dollar_sign;

	dollar_sign = ft_strchr(text, '$');
	res = ft_substr(text, 0, (long)dollar_sign - (long)text);
	if (!res)
		error_exit("malloc failed in interpret_env");
	while (dollar_sign)
	{
		last_name_end_adr = extract_name(name, dollar_sign) + dollar_sign;
		get_env_value(value, name, info);
		res = ft_join_free(res, value);
		if (!res)
			error_exit("malloc failed in interpret_env");
		dollar_sign = ft_strchr(last_name_end_adr, '$');
	}
	if (*last_name_end_adr)
		res = ft_join_free(res, last_name_end_adr);
	if (!res)
		error_exit("malloc failed in interpret_env");
	return (res);
}

int	extract_name(char *name, char *text)
{
	int	i;

	ft_memset(name, 0, 4096);
	i = 0;
	if (text[i + 1] == '?')
	{
		name[0] = '?';
		name[1] = '\0';
		return (2);
	}
	while (text[i + 1] && !is_metachar(text[i + 1]))
	{
		name[i] = text[i + 1];
		i++;
	}
	return (i + 1);
}

char	*get_env_value(char *value, char *name, t_cmd *info)
{
	char	*tmp;

	ft_memset(value, 0, 4096);
	tmp = NULL;
	if (!name[0])
		value[0] = '$';
	if (name[0] == '?')
	{
		tmp = ft_itoa(g_exit_status);
		if (!tmp)
			error_exit("malloc failed in get_env_value");
		ft_strlcpy(value, tmp, ft_strlen(tmp) + 1);
		free(tmp);
		return (value);
	}
	tmp = ft_getenv(name, info->envp);
	if (tmp)
		ft_strlcpy(value, tmp, ft_strlen(tmp) + 1);
	return (value);
}
