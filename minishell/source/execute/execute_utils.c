/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:44:15 by tienshi           #+#    #+#             */
/*   Updated: 2024/12/23 02:05:10 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/utils.h"
#include "../../header/environ.h"
#include "../../header/execute.h"
#include "../../header/errors.h"
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

static int	check_cmd_path(char *cmd)
{
	struct stat	s_stat;

	ft_memset(&s_stat, 0, sizeof(s_stat));
	if (access(cmd, F_OK) != 0)
		return (127);
	if (access(cmd, X_OK) != 0)
		return (126);
	if (stat(cmd, &s_stat) == -1)
	{
		perror("stat");
		return (1);
	}
	if (S_ISDIR(s_stat.st_mode))
	{
		err_mess_2("minishell: ", cmd);
		err_mess(" Is a directory");
		return (126);
	}
	if (!S_ISREG(s_stat.st_mode))
	{
		err_mess("minishell: Not a regular file: ");
		err_mess("cmd");
		return (1);
	}
	return (0);
}

static int	search_cmd_path(char *cmd, char *tmp_paths,
	t_segment *segment)
{
	int		i;
	int		ret;
	char	**paths;
	char	*path;

	i = 0;
	ret = 0;
	if (!tmp_paths)
		return (127);
	paths = ft_split(tmp_paths, ':');
	while (paths[i])
	{
		path = ft_strjoin(paths[i++], cmd);
		if (access(path, F_OK) == 0)
		{
			ret = check_cmd_path(path);
			if (ret == 0)
				segment->cmd_path = path;
			ft_split_free(paths);
			return (ret);
		}
		free(path);
	}
	ft_split_free(paths);
	return (127);
}

int	findpath(char *cmd, t_segment *segment, t_data *data)
{
	int		ret;
	char	*tmp_cmd;
	char	*tmp_paths;

	ret = 0;
	if (ft_strchr(cmd, '/'))
	{
		ret = check_cmd_path(cmd);
		if (ret == 0)
		{
			segment->cmd_path = ft_strdup(cmd);
			if (!segment->cmd_path)
				exit_err("malloc: ft_strdup:findpath", data);
		}
		return (ret);
	}
	tmp_cmd = ft_strjoin("/", cmd);
	tmp_paths = get_val_env("PATH", data, 0, 0);
	ret = search_cmd_path(tmp_cmd, tmp_paths, segment);
	free(tmp_cmd);
	free(tmp_paths);
	return (ret);
}
