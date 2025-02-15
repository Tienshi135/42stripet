/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:49:00 by stripet           #+#    #+#             */
/*   Updated: 2025/01/08 12:07:58 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"
#include "../../header/builtins.h"
#include "../../header/utils.h"
#include "../../header/environ.h"
#include "../../header/execute.h"
#include "../../header/errors.h"
#include "../../header/ft_signal.h"
#include "../../libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

void	handle_pipe(t_data *data, int i, t_io io)
{
	int	num_pipe;

	num_pipe = data->pipeline->num_pipe;
	if (num_pipe == 0)
		return ;
	if (i > 0 && !io.heredoc_f && !io.red_in)
	{
		if (dup2(data->pipeline->pipes[i - 1][0], STDIN_FILENO) ==
				-1)
		{
			perror("dup2: handle_pipe");
			exit(1);
		}
	}
	if (i < num_pipe && !io.red_out && ! io.red_out_app)
	{
		if (dup2(data->pipeline->pipes[i][1], STDOUT_FILENO) == -1)
		{
			perror("dup2: handle_pipe");
			exit(1);
		}
	}
}

static void	execute_segment(t_data *data, t_segment *segment, int i, int ret)
{
	data->pid[data->nb_pid][0] = fork();
	if (data->pid[data->nb_pid][0] == -1)
		exit_err("fork", data);
	if (data->pid[data->nb_pid][0] == 0)
	{
		update_env_last_command(segment->cmd_path, data);
		handle_pipe(data, i, segment->io);
		close_child_pipe(data, i, segment->prev_builtin);
		if (red(&segment->io))
		{
			restore_fd(data->backup_fd);
			exit (1);
		}
		if (ret != 0 || !segment->argv)
			exit (ret);
		restore_default_sig();
		if (execve(segment->cmd_path, segment->argv, data->envp) < 0)
		{
			if (errno == ENOEXEC)
				execute_script(segment, data);
			err_execve(segment->cmd_path);
		}
		else
			execute_script(segment, data);
	}
}

static void	drive_segment_2(t_data *data, t_segment *segment, int i)
{
	int	ret;

	ret = 0;
	if (segment->argv)
		ret = findpath(segment->argv[0], segment, data);
	if (segment->argv && ret != 0)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		if (ret == 127)
			err_mess_2(segment->argv[0], "command not found");
		if (ret == 126)
			err_mess_2(segment->argv[0], "NO access");
		data->return_v = ret;
	}
	if (segment->cmd_path)
	{
		free(segment->argv[0]);
		segment->argv[0] = ft_strdup(segment->cmd_path);
		if (!segment->argv[0])
			exit_err("mallloc", data);
	}
	execute_segment(data, segment, i, ret);
	close_used_pipe(data, i);
	data->pid[data->nb_pid][1] = i;
	data->nb_pid++;
}

static void	drive_segment(t_data *data, t_list *curr_seg)
{
	int			i;
	int			ret;
	t_segment	*segment;

	i = 0;
	while (curr_seg)
	{
		segment = curr_seg->content;
		if (segment->is_builtin == true)
		{
			handle_pipe(data, i, segment->io);
			ret = red(&segment->io);
			if (ret != 0)
				data->return_v = ret;
			else
				do_builtin(data, segment->argv);
			data->pid[data->nb_pid][1] = i;
			data->nb_pid++;
		}
		else if (segment->is_builtin == false)
			drive_segment_2(data, segment, i);
		curr_seg = curr_seg->next;
		backup_std_fd(data->backup_fd);
		i++;
	}
}

void	execute(t_data *data)
{
	t_list	*curr_seg;

	if (!data || !data->pipeline || !data->pipeline->segments)
		return ;
	save_fd(data->backup_fd);
	curr_seg = data->pipeline->segments;
	if (data->pipeline->num_pipe)
		creat_pipe(data, data->pipeline);
	data->pid = ft_calloc(((data->pipeline->num_pipe) + 1), (sizeof(int [2])));
	if (!data->pid)
		exit_err("calloc:", data);
	data->nb_pid = 0;
	drive_segment(data, curr_seg);
	wait_process(data);
	restore_fd(data->backup_fd);
	delete_env_last_command(data);
	free(data->pid);
}
