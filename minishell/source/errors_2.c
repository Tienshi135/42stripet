/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:28:18 by marcgodel         #+#    #+#             */
/*   Updated: 2024/12/23 01:55:47 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <errno.h>
#include "../libft/libft.h"

void	err_mess_export(char *str)
{
	ft_putstr_fd("minishell: export: \" ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(" \" : not a valid identifier:\n", STDERR_FILENO);
}

void	err_message_heredoc(size_t line, char *delimiter)
{
	(void)line;
	ft_putstr_fd("minishell: warning: heredoc delimited by EOF (wanted `",
		STDERR_FILENO);
	ft_putstr_fd(delimiter, STDERR_FILENO);
	ft_putstr_fd("')\n", STDERR_FILENO);
}

void	err_execve(char	*cmd)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	perror(cmd);
	if (errno == ENOENT)
		exit(127);
	else if (errno == EACCES)
		exit(126);
	else if (errno == ENOEXEC)
		exit(126);
	else
		exit(1);
}
