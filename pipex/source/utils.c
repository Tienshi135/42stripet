/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:13:10 by stripet           #+#    #+#             */
/*   Updated: 2024/03/18 14:22:49 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"
#include "../includes/errors.h"

static char	*findpath(char *cmd)
{
	char	*path;

	path = ft_strjoin("/usr/bin/", cmd);
	if (access(path, X_OK) == 0)
		return (path);
	free(path);
	path = ft_strjoin("/bin/", cmd);
	if (access(path, X_OK) == 0)
		return (path);
	free(path);
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
	path = findpath(args[0]);
	if (path == NULL)
	{
		if (args && *args != cmd)
			free(args);
		exit (msg(cmd_err));
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
	path = findpath(args[0]);
	if (path == NULL)
	{
		if (args && *args != cmd)
			free(args);
		exit (msg(cmd_err));
	}
	execve(path, args, NULL);
	free(args);
	free(path);
}
