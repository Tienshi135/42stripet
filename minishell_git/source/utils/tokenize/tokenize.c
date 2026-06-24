/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:52:15 by stripet           #+#    #+#             */
/*   Updated: 2024/12/19 08:04:49 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/tokenize.h"
#include "../../../header/utils.h"
#include "../../../header/errors.h"

static void	check_type(t_type type, int *end)
{
	if (type == REDIR_APPEND || type == REDIR_HERE_DOC || type == OR
		|| type == AND)
		(*end)++;
}

static t_token	*token_extract(t_data *data, int *cursor, int end, t_type type)
{
	t_token	*token;
	char	*temp;
	char	*string;

	string = data->input;
	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		exit_err("malloc", data);
	temp = ft_substr(string, *cursor, (end - *cursor) + 1);
	if (!temp)
		exit_err("malloc", data);
	token->value = ft_strtrim(temp, " ");
	if (temp)
		free(temp);
	if (!token->value)
		exit_err("malloc", data);
	token->type = type;
	token->status = get_tstatus(token->value);
	*cursor = end;
	return (token);
}

static t_token	*handle_tok_2(t_data *data, int *end, int *cursor, t_type type)
{
	t_token	*token;

	(*end)--;
	token = token_extract(data, cursor, *end, WORD);
	if (is_redir_type(type))
	{
		if (ft_isint(token->value))
		{
			token->type = type;
			check_type(type, end);
			*cursor += 1;
		}
	}
	return (token);
}

static void	handle_token(t_data *data, int *end, int *cursor)
{
	t_token		*token;
	t_type		type;

	type = get_type(data->input, *end);
	if (*cursor != *end)
		token = handle_tok_2(data, end, cursor, type);
	else
	{
		check_type(type, end);
		token = token_extract(data, cursor, *end, type);
	}
	*end = *cursor;
	*cursor += 1;
	if (token)
		ft_lstadd_back(&data->tokens, ft_lstnew(token));
}

void	tokenize(t_data *data)
{
	t_status	status;
	t_index		i;

	ft_bzero(&i, sizeof(t_index));
	status = UNQUOTED;
	i.i = (int)ft_strlen(data->input);
	while (data->input[i.cursor] && ft_isspace(data->input[i.cursor]))
		i.cursor++;
	i.end = i.cursor;
	while (i.end <= i.i && data->input[i.cursor] != '\0')
	{
		get_status(&status, data->input[i.end]);
		if (status == UNQUOTED && is_metachara(data->input[i.end]))
		{
			handle_token(data, &i.end, &i.cursor);
			while (data->input[i.cursor] && ft_isspace(data->input[i.cursor]))
			{
				i.end++;
				i.cursor++;
			}
		}
		i.end++;
	}
	if (status != UNQUOTED)
		err_token("Quote note close, (is not to handle)\n", data);
}
