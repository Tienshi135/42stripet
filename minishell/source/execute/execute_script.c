/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_script.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:02:46 by marcgodel         #+#    #+#             */
/*   Updated: 2024/12/23 02:02:32 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "../../header/structures.h"
#include "../../header/errors.h"
#include "../../header/utils.h"

#define INTERPRETER "/bin/bash"

static void	update_argv(t_segment *segment, t_data *data)
{
	size_t	count_arg;
	char	**new_argv;

	count_arg = 0;
	while (segment->argv[count_arg])
		count_arg++;
	count_arg++;
	new_argv = malloc(sizeof(char *) * (count_arg + 1));
	if (!new_argv)
		exit_err("malloc", data);
	new_argv[count_arg] = 0;
	while (--count_arg > 0)
	{
		new_argv[count_arg] = ft_strdup(segment->argv[count_arg - 1]);
		if (!new_argv[count_arg])
			exit_err("malloc", data);
	}
	new_argv[0] = ft_strdup(INTERPRETER);
	free_tab(segment->argv);
	segment->argv = new_argv;
}

static int	check_shebang(t_segment *segment)
{
	int		fd;
	char	buffer[2];
	ssize_t	ret;

	fd = open(segment->cmd_path, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	ret = read(fd, buffer, 2);
	if (close(fd) < 0)
	{
		perror("close");
		exit(1);
	}
	if (ret < 0)
	{
		perror("read");
		exit(1);
	}
	if (ret == 2 && buffer[0] == '#' && buffer[1] == '!')
		return (1);
	return (0);
}

void	execute_script(t_segment *segment, t_data *data)
{
	if (check_shebang(segment))
	{
		if (execve(segment->cmd_path, segment->argv, data->envp) < 0)
			err_execve(segment->cmd_path);
	}
	else
	{
		update_argv(segment, data);
		if (execve(INTERPRETER, segment->argv, data->envp) < 0)
			err_execve(segment->cmd_path);
	}
}
