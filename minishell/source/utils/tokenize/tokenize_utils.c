/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:32:52 by stripet           #+#    #+#             */
/*   Updated: 2024/12/18 16:07:51 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/utils.h"

void	get_status(t_status *status, char c)
{
	if (c == '\"')
	{
		if (*status == DOUBLE_QUOTED)
			*status = UNQUOTED;
		else if (*status == SINGLE_QUOTED)
			*status = SINGLE_QUOTED;
		else
			*status = DOUBLE_QUOTED;
	}
	if (c == '\'')
	{
		if (*status == SINGLE_QUOTED)
			*status = UNQUOTED;
		else if (*status == DOUBLE_QUOTED)
			*status = DOUBLE_QUOTED;
		else
			*status = SINGLE_QUOTED;
	}
}

t_type	get_type(char *str, int cursor)
{
	if (str[cursor] == '>' && str[cursor + 1] == '>')
		return (REDIR_APPEND);
	else if (str[cursor] == '>')
		return (REDIR_OUT);
	else if (str[cursor] == '<' && str[cursor + 1] == '<')
		return (REDIR_HERE_DOC);
	else if (str[cursor] == '<')
		return (REDIR_IN);
	else if (str[cursor] == '|' && str[cursor + 1] == '|')
		return (OR);
	else if (str[cursor] == '|')
		return (PIPE);
	else if (str[cursor] == '&' && str[cursor + 1] == '&')
		return (AND);
	return (WORD);
}

int	get_tstatus(char *string)
{
	if (string[0] == '\"' && string[ft_strlen(string) - 1] == '\"')
		return (DOUBLE_QUOTED);
	if (string[0] == '\'' && string[ft_strlen(string) - 1] == '\'')
		return (SINGLE_QUOTED);
	return (UNQUOTED);
}
