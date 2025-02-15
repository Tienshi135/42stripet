/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:28:30 by marcgodel         #+#    #+#             */
/*   Updated: 2024/12/19 07:42:26 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/parsing.h"
#include "../../header/errors.h"
#include "../../header/utils.h"

static int	pars_pipe_at_end(t_token *prev)
{
	if (prev && prev->type == PIPE)
		return (err_mess_2("Syntax error", prev->value));
	return (0);
}

static int	pars_redir_target(t_list *curr)
{
	if (!curr->next || ((t_token *)curr->next->content)->type != WORD)
		return (err_mess_2("Syntax error", "no target"));
	return (0);
}

static int	pars_double_pipe(t_token *prev)
{
	if (!prev)
		return (err_mess_2("Syntax error", " |"));
	if (prev->type == PIPE)
		return (err_mess_2("Syntax error", prev->value));
	return (0);
}

static int	check_token(t_token *prev, t_token *tok_curr, t_list *curr)
{
	if (tok_curr->type == PIPE)
	{
		if (pars_double_pipe(prev))
			return (1);
	}
	else if (is_redir_type(tok_curr->type))
	{
		if (pars_redir_target(curr))
			return (1);
	}
	else if (tok_curr->type == OR || tok_curr->type == AND)
		return (err_mess_2("not to handle", tok_curr->value));
	return (0);
}

int	pars_token(t_data *data)
{
	t_list	*curr;
	t_token	*prev;
	t_token	*tok_curr;

	curr = data->tokens;
	prev = NULL;
	while (curr)
	{
		tok_curr = curr->content;
		if (check_token(prev, tok_curr, curr))
			return (1);
		prev = curr->content;
		curr = curr->next;
	}
	if (pars_pipe_at_end(prev))
		return (1);
	return (0);
}
