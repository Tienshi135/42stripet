/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:21:09 by marcgodel         #+#    #+#             */
/*   Updated: 2025/01/07 13:56:16 by mgodel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "../header/ft_signal.h"
#include "../header/minishell.h"

volatile sig_atomic_t	g_sig = 0;

void	signal_setup(void)
{
	struct sigaction	s_sig;

	ft_memset(&s_sig, 0, sizeof(s_sig));
	s_sig.sa_handler = handle_sigint;
	sigemptyset(&s_sig.sa_mask);
	if (sigaction(SIGINT, &s_sig, NULL) == -1)
	{
		perror("sigaction");
		exit (1);
	}
	signal(SIGQUIT, SIG_IGN);
}

void	handle_sigint(int sig)
{
	if (g_sig == SIGINT)
	{
		(void)sig;
		write(STDIN_FILENO, "\n", 1);
		g_sig = 0;
		return ;
	}
	rl_on_new_line();
	rl_replace_line("", 1);
	printf("\n");
	rl_redisplay();
}

void	update_sig_heredoc(struct sigaction *s_old_sig)
{
	struct sigaction	s_sig_here;

	ft_memset(&s_sig_here, 0, sizeof(s_sig_here));
	s_sig_here.sa_handler = heredoc_signal_handler;
	if (sigaction(SIGINT, &s_sig_here, s_old_sig) == -1)
	{
		perror("sigaction: update_sig_heredoc");
		exit (1);
	}
}

void	heredoc_signal_handler(int sig)
{
	g_sig = SIGINT;
	(void)sig;
	exit (130);
}

void	restore_sig(struct sigaction *s_old_sig)
{
	if (sigaction(SIGINT, s_old_sig, NULL) == -1)
	{
		perror("sigaction");
		exit (1);
	}
}
