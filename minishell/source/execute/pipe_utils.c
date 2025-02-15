/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 07:57:25 by marcgodel         #+#    #+#             */
/*   Updated: 2024/12/16 13:11:46 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/structures.h"
#include "../../header/errors.h"
#include <stdio.h>

void	close_child_pipe(t_data *data, int current_cmd, t_bool prev_builtin)
{
	int		i;

	i = current_cmd;
	if (i > 0)
	{
		if (prev_builtin == true)
		{
			if (close(data->pipeline->pipes[i - 1][1]))
				perror("close: close_all_child_pipe");
		}
		if (close(data->pipeline->pipes[i - 1][0]))
			perror("close: close_all_child_pipe");
	}
	while (i < data->pipeline->num_pipe)
	{
		if (close(data->pipeline->pipes[i][1]))
			perror("close: close_all_child_pipe");
		if (close(data->pipeline->pipes[i][0]))
			perror("close: close_all_child_pipe");
		i++;
	}
}

void	close_rest_pipe(t_data *data, int current_cmd)
{
	int		i;

	i = current_cmd;
	while (i <= data->pipeline->num_pipe)
	{
		if (i > 0)
		{
			if (close(data->pipeline->pipes[i - 1][0]))
				perror("close: close_rest_pipe");
		}
		if (i != data->pipeline->num_pipe && i != current_cmd)
		{
			if (close(data->pipeline->pipes[i][1]))
				perror("close: close_rest_pipe");
		}
		i++;
	}
}

void	close_used_pipe(t_data *data, int curr_cmd)
{
	if (curr_cmd > 0)
	{
		if (close(data->pipeline->pipes[curr_cmd - 1][0]) == -1)
			perror("close: close_used_pipe");
	}
	if (curr_cmd < data->pipeline->num_pipe)
	{
		if (close(data->pipeline->pipes[curr_cmd][1]) == -1)
			perror("close: close_used_pipe");
	}
}
