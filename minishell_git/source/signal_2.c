/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:05:39 by marcgodel         #+#    #+#             */
/*   Updated: 2025/01/07 13:56:34 by mgodel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <readline/readline.h>
#include "../header/ft_signal.h"
#include "../libft/libft.h"

void	inc_cmd_sig_handle(int sig)
{
	(void)sig;
	g_sig = SIGINT;
	rl_replace_line("", 0);
	rl_on_new_line();
	close(STDIN_FILENO);
}

void	change_sig_inc_cmd(struct sigaction *s_old)
{
	struct sigaction	s_sig;

	ft_memset(&s_sig, 0, sizeof(s_sig));
	s_sig.sa_handler = inc_cmd_sig_handle;
	if (sigaction(SIGINT, &s_sig, s_old) == -1)
	{
		perror("sigaction");
		exit (1);
	}
}

void	restore_default_sig(void)
{
	struct sigaction	s_sig;

	ft_memset(&s_sig, 0, sizeof(s_sig));
	s_sig.sa_handler = SIG_DFL;
	if (sigaction(SIGINT, &s_sig, NULL) == -1)
	{
		perror("sigaction: SIGINT:");
		exit (1);
	}
	if (sigaction(SIGQUIT, &s_sig, NULL) == -1)
	{
		perror("sigaction: SIGQUIT:");
		exit (1);
	}
}
