/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:23:38 by marcgodel         #+#    #+#             */
/*   Updated: 2025/01/08 10:39:26 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../header/structures.h"
#include "../header/execute.h"
#include "../header/errors.h"
#include <fcntl.h>

static void	update_string(t_data *data, char **str, char *tmp)
{
	if (*str)
		free(*str);
	*str = ft_strdup(tmp);
	if (!(*str))
		exit_err("malloc", data);
}

int	handle_redir_out(t_data *data, t_io *io, char *f_name, char *value)
{
	if (check_access_redir_output(f_name))
	{
		io->is_error = true;
		return (1);
	}
	update_string(data, &io->red_out, f_name);
	if (io->red_out_app)
	{
		free(io->red_out_app);
		io->red_out_app = NULL;
	}
	io->fd_out = open(f_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (io->fd_out == -1)
	{
		io->is_error = true;
		return (1);
	}
	if (ft_isint(value))
		io->to_dup_out = ft_atoi(value);
	close(io->fd_out);
	return (0);
}

int	handle_redir_append(t_data *data, t_io *io, char *f_name, char *value)
{
	if (check_access_redir_output(f_name))
	{
		io->is_error = true;
		return (1);
	}
	update_string(data, &io->red_out_app, f_name);
	if (io->red_out)
	{
		free(io->red_out);
		io->red_out = NULL;
	}
	io->fd_out = open(f_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (io->fd_out == -1)
	{
		io->is_error = true;
		return (1);
	}
	if (ft_isint(value))
		io->to_dup_out = ft_atoi(value);
	close(io->fd_out);
	return (0);
}

int	handle_redir_in(t_data *data, t_io *io, char *f_name, char *value)
{
	if (check_access_redir_in(f_name))
	{
		io->is_error = true;
		return (1);
	}
	update_string(data, &io->red_in, f_name);
	if (io->heredoc_f)
	{
		free(io->heredoc_f);
		io->heredoc_f = NULL;
	}
	io->fd_in = open(f_name, O_RDONLY);
	if (io->fd_in == -1)
	{
		io->is_error = true;
		return (1);
	}
	if (ft_isint(value))
		io->to_dup_in = ft_atoi(value);
	close(io->fd_out);
	return (0);
}

int	handle_redir_heredoc(t_data *data, t_io *io, char *f_name)
{
	update_string(data, &io->heredoc_f, f_name);
	if (io->red_in)
	{
		free(io->red_in);
		io->red_in = NULL;
	}
	io->fd_in = open(f_name, O_RDONLY);
	if (io->fd_in == -1)
		return (err_mess_2("open:", f_name));
	close(io->fd_in);
	return (0);
}
