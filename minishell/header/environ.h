/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcgodel <mgodel@student.42lausanne.ch>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:52:41 by marcgodel         #+#    #+#             */
/*   Updated: 2025/02/04 10:02:24 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRON_H
# define ENVIRON_H

# include "structures.h"

// Prototype: environ.c
void	delete_env_last_command(t_data *data);
void	update_env_last_command(char *path, t_data *data);
int		is_this_var_env(char *str_env, char *new_var, size_t len);
int		is_var_env(char *str);
char	*get_val_env(char *var_name, t_data *data, size_t i, size_t j);

// Prototype: environ_utils.c
int		get_env_variable(t_token *token, int cursor, t_data *data, int len);

// Prototype: environ_utils_2.c
void	look_shlvl(t_data *data);
void	init_env(t_data *data, char **environ);

#endif
