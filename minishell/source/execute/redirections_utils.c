/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:43:37 by marcgodel         #+#    #+#             */
/*   Updated: 2024/12/16 08:26:39 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

void	save_fd(int *backup_fd)
{
	backup_fd[0] = dup(STDIN_FILENO);
	if (backup_fd[0] == -1)
		perror("dup");
	backup_fd[1] = dup(STDOUT_FILENO);
	if (backup_fd[1] == -1)
		perror("dup");
	backup_fd[2] = dup(STDERR_FILENO);
	if (backup_fd[2] == -1)
		perror("dup");
}

void	restore_fd(int *backup_fd)
{
	if (dup2(backup_fd[0], STDIN_FILENO) == -1)
		perror("dup2: restore_fd: (backup_fd[0]):");
	close(backup_fd[0]);
	if (dup2(backup_fd[1], STDOUT_FILENO) == -1)
		perror("dup2: restore_fd: (backup_fd[1]):");
	close(backup_fd[1]);
	if (dup2(backup_fd[2], STDERR_FILENO) == -1)
		perror("dup2: restore_fd: (backup_fd[2]):");
	close(backup_fd[2]);
}

void	backup_std_fd(int *backup_fd)
{
	if (dup2(backup_fd[0], STDIN_FILENO) == -1)
		perror("dup2: backup_std_fd:");
	if (dup2(backup_fd[1], STDOUT_FILENO) == -1)
		perror("dup2: backup_std_fd:");
	if (dup2(backup_fd[2], STDERR_FILENO) == -1)
		perror("dup2: backup_std_fd");
}
