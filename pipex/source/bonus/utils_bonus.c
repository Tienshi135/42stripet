/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:13:10 by stripet           #+#    #+#             */
/*   Updated: 2024/03/20 15:59:33 by stripet          ###   ########.fr       */
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
			return (path);
		}
		free(path);
		i++;
	}
	free(cmd);
	ft_split_free(paths);
	return (NULL);
}

void	childpipexlast(t_data data, char *cmd)
{
	char	**args;
	char	*path;

	dup2(data.pipe[0], STDIN_FILENO);
	dup2(data.output, STDOUT_FILENO);
	close(data.pipe[1]);
	close(data.pipe[0]);
	close(data.output);
	close(data.input);
	args = ft_split(cmd, ' ');
	path = findpath(data, args[0]);
	if (path == NULL)
	{
		if (args && *args != cmd)
			free(args);
		exit (msg(data, cmd_err));
	}
	execve(path, args, NULL);
	free(args);
	free(path);
}

void	childpipexfirst(t_data data, char *cmd)
{
	char	*path;
	char	**args;

	dup2(data.pipe[1], STDOUT_FILENO);
	dup2(data.input, STDIN_FILENO);
	close(data.pipe[0]);
	close(data.pipe[1]);
	close(data.input);
	close(data.output);
	args = ft_split(cmd, ' ');
	path = findpath(data, args[0]);
	if (path == NULL)
	{
		if (args && *args != cmd)
			free(args);
		exit (msg(data, cmd_err));
	}
	execve(path, args, NULL);
	free(args);
	free(path);
}
