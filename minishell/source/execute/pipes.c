/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:00:31 by tienshi           #+#    #+#             */
/*   Updated: 2024/12/15 14:49:10 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/execute.h"
#include "../../header/errors.h"
#include "../../header/utils.h"

void	creat_pipe(t_data *data, t_pipeline *pipeline)
{
	int	i;
	int	nb_pipe;

	i = 0;
	nb_pipe = pipeline->num_pipe;
	pipeline->pipes = ft_calloc(nb_pipe, sizeof(int *));
	if (!pipeline->pipes)
		exit_err("malloc", data);
	while (i < nb_pipe)
	{
		pipeline->pipes[i] = malloc(sizeof(int) * 2);
		if (!pipeline->pipes[i])
		{
			pipeline->num_pipe = i - 1;
			exit_err("malloc", data);
		}
		i++;
	}
	i = 0;
	while (i < nb_pipe)
	{
		if (pipe(pipeline->pipes[i]) != 0)
			exit_err("pipe", data);
		i++;
	}
}
