/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:12:33 by stripet           #+#    #+#             */
/*   Updated: 2024/12/12 20:51:02 by marcgodel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "utils.h"

//prototype: builtins.c
int		is_builtin(char *str);
int		do_builtin(t_data *data, char **argv);

//prototype: cd.c
int		ft_cd(char **arguments, t_data *data, char *buff, char *old_pwd);

//prototype: echo.c
int		ft_echo(char **arguments);

//prototype: env.c
int		ft_env(t_data *data);

//protoype: exit.c
void	ft_exit(t_data *data, char **arguments);

//prototype: export.c
int		ft_export(t_data *data, char **arguments);

//prototype: pwd.c
int		ft_pwd(char **arguments);

//prototype: unset.c
void	clean_var_env(t_data *data, size_t i);
int		ft_unset(t_data *data, char **arguments);

//prototype: export.c
int		display_env_var(t_data *data);
void	free_tab(char **tab);
int		export_variable(char *var_name, char *new_var, t_data *data);

#endif
