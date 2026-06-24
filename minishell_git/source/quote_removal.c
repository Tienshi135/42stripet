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

static void	quote_2_rem(const char *str, char *result)
{
	size_t	i;
	size_t	j;
	char	quote;

	i = 0;
	j = 0;
	quote = '\0';
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
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
		quote_2_rem(curr->value, result);
		free(curr->value);
		curr->value = result;
		tmp = tmp->next;
	}
}
