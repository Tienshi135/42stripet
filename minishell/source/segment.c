/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:29:08 by marcgodel         #+#    #+#             */
/*   Updated: 2025/01/08 10:39:35 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../header/segment.h"
#include "../header/errors.h"
#include "../header/utils.h"
#include "../header/heredoc.h"
#include "../header/builtins.h"
#include "../header/ft_signal.h"

static t_segment	*init_segment(t_data *data)
{
	t_segment	*new;

	new = ft_calloc(1, sizeof(t_segment));
	if (!new)
		exit_err("ft_calloc", data);
	new->io.fd_in = -1;
	new->io.fd_out = -1;
	new->io.to_dup_in = -1;
	new->io.to_dup_out = -1;
	return (new);
}

static t_pipeline	*init_pipeline(t_data *data)
{
	t_pipeline	*new;

	new = ft_calloc(sizeof(t_pipeline), 1);
	if (!new)
		exit_err("malloc", data);
	return (new);
}

/* return curr->next to jump the target */
static t_list	*get_redirection(t_data *data, t_list *curr, t_segment *seg)
{
	char	*next_val;
	char	*curr_val;

	if (!seg || !curr)
		return (curr);
	if (seg->io.is_error == true)
		return (curr->next);
	curr_val = ((t_token *)curr->content)->value;
	next_val = ((t_token *)curr->next->content)->value;
	if (((t_token *)curr->content)->type == REDIR_OUT)
		handle_redir_out(data, &seg->io, next_val, curr_val);
	else if (((t_token *)curr->content)->type == REDIR_APPEND)
		handle_redir_append(data, &seg->io, next_val, curr_val);
	else if (((t_token *)curr->content)->type == REDIR_IN)
		handle_redir_in(data, &seg->io, next_val, curr_val);
	else if (((t_token *)curr->content)->type == REDIR_HERE_DOC)
	{
		handle_heredoc(data, curr->content, next_val);
		if (g_sig == SIGINT)
			return (NULL);
		curr_val = ((t_token *)curr->content)->value;
		handle_redir_heredoc(data, &seg->io, curr_val);
	}
	return (curr->next);
}

static void	get_segment(t_data *data, t_pipeline *pipeline, t_list *curr)
{
	t_segment	*seg;
	t_token		*tok_cur;

	seg = NULL;
	while (curr)
	{
		tok_cur = (t_token *)curr->content;
		if (!seg)
			seg = init_segment(data);
		if (tok_cur->type == WORD && seg->argv == NULL
			&& seg->io.is_error == false)
			seg->argv = get_command_args(curr, data);
		else if (is_redir_type(tok_cur->type))
			curr = get_redirection(data, curr, seg);
		else if (tok_cur->type == PIPE)
		{
			ft_lstadd_back(&pipeline->segments, ft_lstnew(seg));
			seg = NULL;
			pipeline->num_pipe++;
		}
		if (curr)
			curr = curr->next;
	}
	if (seg)
		ft_lstadd_back(&pipeline->segments, ft_lstnew(seg));
}

void	creat_segment(t_data *data)
{
	t_pipeline	*pipeline;

	if (!data || !data->tokens)
		return ;
	pipeline = init_pipeline(data);
	get_segment(data, pipeline, data->tokens);
	if (g_sig == SIGINT)
		return ;
	check_builtin_segment(pipeline->segments);
	data->pipeline = pipeline;
	ft_lstclear(&data->tokens, free_token);
}
