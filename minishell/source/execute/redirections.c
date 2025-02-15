/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:29:46 by stripet           #+#    #+#             */
/*   Updated: 2025/01/08 12:11:07 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/execute.h"
#include "../../header/errors.h"
#include "../../header/structures.h"
#include <fcntl.h>
#include <stdio.h>
#include <readline/readline.h>

static int	red_out(t_io *io, char *f_name)
{
	int	to_dup;
	int	ret;

	ret = check_access_redir_output(f_name);
	if (ret != 0)
		return (ret);
	if (io->to_dup_out != -1)
		to_dup = io->to_dup_out;
	else
		to_dup = STDOUT_FILENO;
	io->fd_out = open(io->red_out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (io->fd_out == -1)
		return (err_mess_2("open:", f_name));
	if (dup2(io->fd_out, to_dup) == -1)
		return (err_mess_2("open:", f_name));
	close(io->fd_out);
	return (0);
}

static int	red_in(t_io *io, char *f_name)
{
	int	to_dup;
	int	ret;

	ret = check_access_redir_in(f_name);
	if (ret != 0)
		return (ret);
	if (io->to_dup_in != -1)
		to_dup = io->to_dup_in;
	else
		to_dup = STDIN_FILENO;
	io->fd_in = open(f_name, O_RDONLY);
	if (io->fd_in == -1)
		return (err_mess_2("open:", f_name));
	else if (dup2(io->fd_in, to_dup) == -1)
		return (err_mess_2("open:", f_name));
	close(io->fd_in);
	return (0);
}

static int	red_append(t_io *io, char *f_name)
{
	int	to_dup;
	int	ret;

	ret = check_access_redir_output(f_name);
	if (ret != 0)
		return (ret);
	if (io->to_dup_out != -1)
		to_dup = io->to_dup_out;
	else
		to_dup = STDOUT_FILENO;
	io->fd_out = open(f_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (io->fd_out == -1)
		return (err_mess_2("open:", f_name));
	if (dup2(io->fd_out, to_dup) == -1)
		return (err_mess_2("open:", f_name));
	close(io->fd_out);
	return (0);
}

int	red(t_io *io)
{
	int	ret;

	ret = 0;
	if (io->is_error == true)
		return (1);
	if (io->red_in)
		ret = red_in(io, io->red_in);
	else if (io->heredoc_f && ret == 0)
		ret = red_in(io, io->heredoc_f);
	if (io->red_out && ret == 0)
		ret = red_out(io, io->red_out);
	else if (io->red_out_app && ret == 0)
		ret = red_append(io, io->red_out_app);
	return (ret);
}
