/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:23:04 by stripet           #+#    #+#             */
/*   Updated: 2025/01/06 20:00:21 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/utils.h"
#include "../../header/errors.h"

int	is_metachara(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '|'
		|| c == '<' || c == '>' || c == '\0')
		return (1);
	return (0);
}

int	is_separator(char c)
{
	if (c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}

int	has_red(t_data *data)
{
	t_list	*lst;

	lst = data->tokens;
	while (lst)
	{
		if (((t_token *)lst->content)->type >= 1
			&& ((t_token *)lst->content)->type <= 3)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	is_incomplete_cmd(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = ft_strlen(str);
	if (len > 0)
		len--;
	while (len > 0 && ft_isspace(str[len]))
		len--;
	if (len > 0 && str[len] == '|')
		return (1);
	return (0);
}

char	*safe_ft_strjoin(char *str1, char *str2, t_data *data)
{
	char	*new;

	new = ft_strjoin(str1, str2);
	if (!new)
		exit_err("ft_strjoin", data);
	return (new);
}
