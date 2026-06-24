/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_incomplete_cmd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 01:55:42 by marcgodel         #+#    #+#             */
/*   Updated: 2025/01/07 14:03:24 by mgodel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../header/minishell.h"
#include "../header/ft_signal.h"
#include "../header/utils.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>

static void	update_cmd(char **cmd, char *line)
{
	char	*add_space;
	char	*new_cmd;

	add_space = ft_strjoin(*cmd, " ");
	free(*cmd);
	new_cmd = ft_strjoin(add_space, line);
	free(add_space);
	free(line);
	*cmd = new_cmd;
}

static void	exit_minishell_with_err(t_data *data, char *cmd)
{
	ft_putstr_fd("minishell: syntax error:unexpected end of file\n",
		STDERR_FILENO);
	add_history(cmd);
	update_history_file(cmd, data);
	handle_stop(data);
}

void	handle_incomplete_cmd(char **cmd, t_data *data)
{
	char				*tty_name;
	char				*line;
	struct sigaction	s_old;

	tty_name = ttyname(STDIN_FILENO);
	change_sig_inc_cmd(&s_old);
	while (is_incomplete_cmd(*cmd))
	{
		line = readline("> ");
		if (g_sig == SIGINT)
		{
			open(tty_name, O_RDONLY);
			data->return_v = 130;
			return ;
		}
		if (!line)
			exit_minishell_with_err(data, *cmd);
		update_cmd(cmd, line);
	}
	restore_sig(&s_old);
}
