/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:23:04 by stripet           #+#    #+#             */
/*   Updated: 2024/07/24 14:42:39 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils.h"
#include "../header/parse.h"

void	print_tokens(t_list *tokens)
{
	t_list	*tmp;

	tmp = tokens;
	while (tmp)
	{
		printf("Token : %s\n", tmp->content);
		tmp = tmp->next;
	}
}	

int	is_separator(char c, t_status status)
{
	if (c == ' ' && status == UNQUOTED)
		return (1);
	if (c == '<' && status == UNQUOTED)
		return (1);
	if (c == '>' && status == UNQUOTED)
		return (1);
	if (c == '|' && status == UNQUOTED)
		return (1);
	return (0);
}

int	parse(t_data *data)//for now only handle basic tokenization on < > << >> | and space
{
	t_status	status;
	int			i;
	int			cursor;

	i = 0;
	cursor = 0;
	status = UNQUOTED;
	while (i <= (int) ft_strlen(data->input))
	{
		get_status(&status, data->input[i]);
		printf("Status : %d\n", status);//debug
		if (is_separator(data->input[i], status) || !data->input[i])
		{
			ft_lstadd_back(&data->tokens, ft_lstnew(ft_substr(data->input, cursor, i - cursor)));
			if (data->input[i] && data->input[i] != ' ')
			{
				if (is_separator(data->input[i + 1], status)
					&& data->input[i] == data->input[i + 1])
					ft_lstadd_back(&data->tokens, ft_lstnew(ft_substr(data->input, i++, 2)));
				else
					ft_lstadd_back(&data->tokens, ft_lstnew(ft_substr(data->input, i, 1)));
			}
			cursor = i + 1;
		}
		i++;
	}
	print_tokens(data->tokens);
	return (0);
}

void	testing(t_data *data)//list being on commands rather than tokens
{
	t_status	status;
	int			i;

	i = 0;
	status = UNQUOTED;
	while (data.input[i])
	{
		get_status(&status, data.input[i]);
		printf("Status : %d\n", status);//debug
	}
}
