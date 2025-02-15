/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 02:50:45 by tienshi           #+#    #+#             */
/*   Updated: 2024/12/21 22:05:46 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "structures.h"

//prototype: errors.c
int		err_mess(char *str);
int		err_mess_2(char *str, char *str2);
void	err_clean(t_data *data);
void	exit_err(char *str, t_data *data);
void	err_token(char *str, t_data *data);

//prototype: errors_2.c
void	err_mess_export(char *str);
void	err_message_heredoc(size_t line, char *delimiter);
void	err_execve(char	*cmd);

// error messages
# define ERR_SYNTAX "minishell: syntax error near unexpected token"

#endif
