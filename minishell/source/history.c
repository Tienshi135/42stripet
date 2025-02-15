/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:40:06 by marcgodel         #+#    #+#             */
/*   Updated: 2025/01/07 11:44:39 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../header/structures.h"
#include "../header/minishell.h"
#include "../header/environ.h"
#include "../header/utils.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <readline/history.h>

static void	read_minishell_history(int fd)
{
	char	*cmd;
	size_t	len;

	while (1)
	{
		cmd = get_next_line(fd);
		if (!cmd)
			return ;
		len = ft_strlen(cmd);
		if (len > 0 && cmd[len - 1] == '\n')
			cmd[len - 1] = '\0';
		add_history(cmd);
		if (cmd)
		{
			free(cmd);
			cmd = NULL;
		}
	}
}

void	update_history(t_data *data)
{
	int		fd;
	char	*tmp;

	tmp = getenv("HOME");
	data->hist_file = ft_strjoin(tmp, "/.minishell_history");
	fd = open(data->hist_file, O_RDONLY | O_CREAT, 0600);
	if (fd < 0)
	{
		free(data->hist_file);
		data->hist_file = NULL;
		return ;
	}
	read_minishell_history(fd);
	close(fd);
}

void	update_history_file(char *command, t_data *data)
{
	int	fd_history;

	if (!data->hist_file)
		return ;
	fd_history = open(data->hist_file, O_WRONLY | O_APPEND
			| O_CREAT, 0600);
	if (fd_history < 0)
	{
		perror("open");
		clear_data(data);
		exit(1);
	}
	ft_putstr_fd(command, fd_history);
	ft_putchar_fd('\n', fd_history);
	close(fd_history);
}
