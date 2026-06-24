/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_access.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:04:32 by marcgodel         #+#    #+#             */
/*   Updated: 2025/01/09 09:54:11 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/errors.h"
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>

static void	err_mess_3(char *mes1, char *mes2, char *mes3)
{
	ft_putstr_fd(mes1, STDERR_FILENO);
	ft_putstr_fd(mes2, STDERR_FILENO);
	ft_putstr_fd(mes3, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

int	check_access_redir_in(char *file)
{
	struct stat	s_stat;

	if (access(file, F_OK) != 0)
	{
		err_mess_3("minishell: ", file, " No such file or directory");
		return (127);
	}
	if (access(file, R_OK) != 0)
	{
		err_mess_3("minishell: ", file, "Permission denied");
		return (126);
	}
	if (stat(file, &s_stat) == -1)
	{
		perror("minishell");
		return (1);
	}
	if (S_ISDIR(s_stat.st_mode))
	{
		err_mess_3("minishell: ", file, "Is a directory");
		return (126);
	}
	return (0);
}

int	check_access_redir_output(char *file)
{
	struct stat	s_stat;

	if (stat(file, &s_stat) == 0)
	{
		if (S_ISDIR(s_stat.st_mode))
		{
			err_mess_3("minishell: ", file, "Is a directory");
			return (126);
		}
		if (access(file, W_OK) != 0)
		{
			err_mess_3("minishell: ", file, "Permission denied");
			return (126);
		}
	}
	else if (errno != ENOENT)
	{
		perror("minishell");
		return (1);
	}
	return (0);
}
