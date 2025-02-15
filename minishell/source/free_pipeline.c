/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:52:20 by marcgodel         #+#    #+#             */
/*   Updated: 2024/12/21 16:28:49 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils.h"

static void	free_io(t_io *io)
{
	if (io->heredoc_f)
	{
		clean_heredoc(io->heredoc_f);
		free(io->heredoc_f);
	}
	if (io->red_in)
		free(io->red_in);
	if (io->red_out)
		free(io->red_out);
	if (io->red_out_app)
		free(io->red_out_app);
}

void	free_pipeline(t_pipeline *pipeline)
{
	t_list		*node;
	t_segment	*seg;

	if (!pipeline)
		return ;
	if (pipeline->segments)
	{
		node = pipeline->segments;
		while (node)
		{
			seg = (t_segment *)node->content;
			if (seg->argv)
				free_tab(seg->argv);
			if (seg->cmd_path)
				free(seg->cmd_path);
			free_io(&seg->io);
			node = node->next;
		}
	}
	if (pipeline->pipes)
		free_pipe(pipeline->pipes, pipeline->num_pipe);
	ft_lstclear(&pipeline->segments, free);
	free(pipeline);
}
