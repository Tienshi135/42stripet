/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 02:44:07 by tienshi           #+#    #+#             */
/*   Updated: 2024/12/24 01:58:46 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "structures.h"

//prototype: history.c
void	update_history(t_data *data);
void	update_history_file(char *command, t_data *data);

//prototype: minishell.c
void	handle_stop(t_data *data);
int		main(int argc, char **argv, char **env);

//prototype: handle_incomplete_cmd.c
void	handle_incomplete_cmd(char **cmd, t_data *data);

#endif
