/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_removal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:54:05 by marcgodel         #+#    #+#             */
/*   Updated: 2024/12/19 08:24:02 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/errors.h"
#include "../header/structures.h"
#include <stdlib.h>

static char	quote_3(t_status status)
{
	char	c;

	if (status == DOUBLE_QUOTED)
		c = '\"';
	else
		c = '\'';
	return (c);
}

static void	quote_2(t_token *curr, char *result, size_t i, size_t j)
{
	const char	*str;
	char		quote;
	char		c;

	str = curr->value;
	c = quote_3(curr->status);
	quote = '\0';
	while (str[i])
	{
		if (str[i] == c)
		{
			if (quote == '\0')
				quote = str[i];
			else if (quote == str[i])
				quote = '\0';
			else
				result[j++] = str[i];
		}
		else
			result[j++] = str[i];
		i++;
	}
	result[j] = '\0';
}

void	quote_removal(t_data *data)
{
	t_list	*tmp;
	t_token	*curr;
	char	*result;

	if (!data)
		return ;
	tmp = data->tokens;
	while (tmp)
	{
		curr = (t_token *)tmp->content;
		result = ft_calloc(1, sizeof(char) * (ft_strlen(curr->value)
					+ 1));
		if (!result)
			exit_err("ft_calloc", data);
		quote_2(curr, result, 0, 0);
		free(curr->value);
		curr->value = result;
		tmp = tmp->next;
	}
}
