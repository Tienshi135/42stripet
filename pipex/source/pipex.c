/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:08:38 by stripet           #+#    #+#             */
/*   Updated: 2024/04/04 16:43:08 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../includes/utils.h"
#include "../includes/structures.h"
#include "../libft/libft.h"
#include "../includes/errors.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

static void	cleanup(t_data data)
{
	close(data.pipe[0]);
	close(data.pipe[1]);
	close(data.input);
	close(data.output);
	waitpid(data.id1, NULL, 0);
	waitpid(data.id2, NULL, 0);
	free(data.paths);
}

char	*find_path_envp(char **envp)
{
	if (!envp)
	{
		ft_printf("Error envp is empty\n");
		exit (-9999999);
	}
	while (*envp)
	{
		if (ft_strlen(*envp) < 4)
			envp++;
		if (ft_strncmp(*envp, "PATH", 4) == 0)
			return (ft_strtrim(*envp, "PATH="));
		else
			envp++;
	}
	return (NULL);
}

int	init(t_data *data, char **argv, char **envp)
{
	data->paths = find_path_envp(envp);
	data->input = open(argv[1], O_RDONLY);
	if (data->input < 0)
		return (msg(*data, open_err));
	data->output = open(argv[4], O_CREAT | O_WRONLY, S_IRWXU);
	if (data->output < 0)
		return (msg(*data, opencreat_err));
	data->rval = pipe(data->pipe);
	if (data->rval == -1)
		return (msg(*data, pipe_err));
	return (0);
}

int	main(int argc, char**argv, char **envp)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (argc != 5)
		return (msg(data, badargs_err));
	init(&data, argv, envp);
	data.id1 = fork();
	if (data.id1 < 0)
		return (msg(data, fork_err));
	if (data.id1 == 0)
		childpipexfirst(data, argv[2]);
	data.id2 = fork();
	if (data.id2 < 0)
		return (msg(data, fork_err));
	if (data.id2 == 0)
		childpipexlast(data, argv[3]);
	cleanup(data);
}
