/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:15:19 by marcgodel         #+#    #+#             */
/*   Updated: 2025/01/09 10:00:22 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include "../../header/ft_signal.h"
#include "../../header/structures.h"
#include "../../header/errors.h"
#include "../../header/execute.h"
#include <stdio.h>

static int	close_builtin_pipes(t_data *data, int i)
{
	int	num_close;

	num_close = 0;
	while (i < data->nb_pid || (data->nb_pid == 1 && i == 0))
	{
		if (data->pid[i][0] == 0)
		{
			close_used_pipe(data, data->pid[i][1]);
			num_close++;
		}
		i++;
	}
	return (num_close);
}

static int	look_end_processus(t_data *data, int status, int i, int ret)
{
	ret = waitpid(data->pid[i][0], &status, WNOHANG);
	if (ret > 0)
	{
		if (WIFSIGNALED(status) && i == data->nb_pid - 1)
		{
			data->return_v = WTERMSIG(status);
			data->return_v += 128;
			if (data->return_v == SIGINT)
				g_sig = SIGINT;
		}
		else if (i == data->nb_pid - 1)
			data->return_v = WEXITSTATUS(status);
		data->pid[i][0] = 0;
		return (1);
	}
	else if (ret < 0)
		exit_err("waitpid", data);
	return (0);
}

static void	go_waitpid_and_close_pipe(t_data *data, int i)
{
	int	num_close;

	num_close = close_builtin_pipes(data, 0);
	while (num_close != data->nb_pid)
	{
		if (data->pid[i][0] != 0)
		{
			if (look_end_processus(data, 0, i, 0) == 1)
				num_close++;
		}
		i++;
		if (i == data->nb_pid)
			i = 0;
	}
}

void	wait_process(t_data *data)
{
	struct sigaction	s_old;
	struct sigaction	s_sig;

	ft_memset(&s_sig, 0, sizeof(s_sig));
	ft_memset(&s_old, 0, sizeof(s_old));
	s_sig.sa_handler = SIG_IGN;
	if (sigaction(SIGINT, &s_sig, &s_old) == -1)
		perror("sigaction");
	go_waitpid_and_close_pipe(data, 0);
	if (sigaction(SIGINT, &s_old, &s_sig))
		perror("sigaction");
}

void	wait_heredoc(t_data *data, int pid)
{
	int	sig_tmp;
	int	status;

	sig_tmp = 0;
	while (waitpid(pid, &status, 0) == -1)
	{
		if (errno != EINTR)
		{
			perror("waitpid");
			break ;
		}
	}
	if (WEXITSTATUS(status))
	{
		sig_tmp = WEXITSTATUS(status);
		if (sig_tmp == 130)
			g_sig = SIGINT;
		else
			g_sig = sig_tmp;
		data->return_v = WEXITSTATUS(status);
	}
}
