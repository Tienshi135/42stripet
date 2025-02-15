/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:16:12 by stripet           #+#    #+#             */
/*   Updated: 2025/01/07 17:04:40 by mgodel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNAL_H
# define FT_SIGNAL_H

# include <signal.h>

extern volatile sig_atomic_t	g_sig;

// prototype: signal.c
void	handle_sigint(int sig);
void	update_sig_heredoc(struct sigaction *s_old_sig);
void	signal_setup(void);
void	heredoc_signal_handler(int sig);
void	restore_sig(struct sigaction *s_old_sig);

// prototype: signal_2.c
void	inc_cmd_sig_handle(int sig);
void	change_sig_inc_cmd(struct sigaction *s_old);
void	restore_default_sig(void);

#endif
