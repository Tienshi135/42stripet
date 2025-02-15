/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:09:37 by marcgodel         #+#    #+#             */
/*   Updated: 2025/01/07 13:59:10 by mgodel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/heredoc.h"
#include "../header/errors.h"
#include "../header/ft_signal.h"
#include "../header/execute.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

static void	readline_heredoc(int fd, char *delimiter, size_t len)
{
	char	*line;
	size_t	nb_line;

	nb_line = 0;
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			err_message_heredoc(nb_line, delimiter);
			break ;
		}
		if (ft_strncmp(line, delimiter, len) == 0)
		{
			free(line);
			break ;
		}
		nb_line++;
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
}

static void	populate_heredoc(int fd, char *delimiter)
{
	size_t				len;
	struct sigaction	s_old_sig;

	g_sig = 0;
	ft_memset(&s_old_sig, 0, sizeof(s_old_sig));
	update_sig_heredoc(&s_old_sig);
	len = ft_strlen(delimiter);
	readline_heredoc(fd, delimiter, len);
	close(fd);
	restore_sig(&s_old_sig);
}

static char	*make_name(t_data *data)
{
	char		*name;
	char		*number;
	static int	num = 0;

	number = ft_itoa(num);
	name = ft_strjoin(HEREDOC_TMP_NAME, number);
	free(number);
	num++;
	if (!name)
		exit_err("malloc: heredoc_name:", data);
	return (name);
}

static void	process_here_doc(t_data *data, t_token *curr, char *delimiter)
{
	int	fd;
	int	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit_err("handle_heredoc", data);
	}
	if (pid == 0)
	{
		fd = open(curr->value, O_RDWR | O_CREAT | O_TRUNC, 0600);
		if (fd == -1)
			perror("heredoc: open");
		populate_heredoc(fd, delimiter);
		exit (0);
	}
	wait_heredoc(data, pid);
}

void	handle_heredoc(t_data *data, t_token *curr, char *delimiter)
{
	struct sigaction	s_old;
	struct sigaction	s_sig;

	if (!curr || !delimiter)
		return ;
	ft_memset(&s_sig, 0, sizeof(s_sig));
	ft_memset(&s_old, 0, sizeof(s_old));
	s_sig.sa_handler = SIG_IGN;
	free(curr->value);
	curr->value = make_name(data);
	if (sigaction(SIGINT, &s_sig, &s_old) == -1)
		perror("sigaction");
	process_here_doc(data, curr, delimiter);
	if (sigaction(SIGINT, &s_old, &s_sig))
		perror("sigaction");
}
