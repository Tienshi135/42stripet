/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:56:43 by marcgodel         #+#    #+#             */
/*   Updated: 2025/01/07 14:00:48 by mgodel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../header/structures.h"
#include "../../header/utils.h"
#include "../../header/ft_signal.h"
#include <unistd.h>
#include <stdio.h>

void	free_token(void *to_free)
{
	t_token	*buffer;

	if (!to_free)
		return ;
	buffer = (t_token *)to_free;
	if (buffer->value)
		free(buffer->value);
	if (buffer)
		free(buffer);
}

void	free_for_continue(t_data *data)
{
	if (data->pipeline)
		free_pipeline(data->pipeline);
	data->pipeline = NULL;
	if (data->tokens)
		ft_lstclear(&data->tokens, free_token);
}

void	clean_heredoc(char *heredoc_f)
{
	if (unlink(heredoc_f) != 0)
		perror("unlink");
}
