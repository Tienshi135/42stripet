/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:13:10 by stripet           #+#    #+#             */
/*   Updated: 2024/04/04 16:48:58 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/utils_bonus.h"
#include "../../includes/bonus/errors_bonus.h"

static char	*findpath(t_data data, char *cmd)
{
	char	**paths;
	char	*path;
	int		i;

	if (!cmd)
		return (NULL);
	i = 0;
	cmd = ft_strjoin("/", cmd);
	paths = ft_split(data.paths, ':');
	while (paths[i])
	{
		path = ft_strjoin(paths[i], cmd);
		if (access(path, X_OK) == 0)
		{
			free(cmd);
			ft_split_free(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free(cmd);
	ft_split_free(paths);
	return (NULL);
}

void	child_proccess(t_data data, char *cmd)
{
	int		fd[2];
	int		pid;
	char	*path;
	char	**args;

	if (pipe(fd) == -1)
		msg(data, pipe_err);
	pid = fork();
	if (pid == -1)
		msg (data, fork_err);
	if (pid == 0)
	{
		args = ft_split(cmd, ' ');
		path = findpath(data, args[0]);
		if (!path)
		{
			if (args && *args != cmd)
				free(args);
			msg(data, cmd_err);
		}
		close (fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			msg(data, dup_err);
		execve(path, args, NULL);
	}
	else
	{
		close (fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	last_cmd(t_data data, char *cmd)
{
	int		pid;
	char	*path;
	char	**args;

	pid = fork();
	if (pid == -1)
		msg(data, fork_err);
	else if (pid != 0)
	{
		args = ft_split(cmd, ' ');
		path = findpath(data, args[0]);
		if (!path)
			msg(data, cmd_err);
		if (dup2(data.output, STDOUT_FILENO) == -1)
			msg(data, dup_err);
		execve(path, args, NULL);
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
}
