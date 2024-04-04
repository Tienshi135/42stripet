/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:13:10 by stripet           #+#    #+#             */
/*   Updated: 2024/04/04 16:45:56 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"
#include "../includes/errors.h"

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

void	childpipexfirst(t_data data, char *cmd)
{
	char	*path;
	char	**args;

	dup2(data.pipe[1], STDOUT_FILENO);
	dup2(data.input, STDIN_FILENO);
	close(data.pipe[0]);
	args = ft_split(cmd, ' ');
	path = findpath(data, args[0]);
	if (path == NULL)
	{
		if (args && *args != cmd)
			free(args);
		msg(data, cmd_err);
	}
	execve(path, args, NULL);
}

void	childpipexlast(t_data data, char *cmd)
{
	char	**args;
	char	*path;

	dup2(data.pipe[0], STDIN_FILENO);
	dup2(data.output, STDOUT_FILENO);
	close(data.pipe[1]);
	args = ft_split(cmd, ' ');
	path = findpath(data, args[0]);
	if (path == NULL)
	{
		if (args && *args != cmd)
			free(args);
		msg(data, cmd_err);
	}
	execve(path, args, NULL);
}
