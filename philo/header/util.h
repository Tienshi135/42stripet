/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:39:46 by stripet           #+#    #+#             */
/*   Updated: 2024/05/27 16:04:20 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "stdlib.h"
# include "../header/structure.h"
# include "stdio.h"
# include "unistd.h"

int		ph_atoi(const char *str);
void	mutex_init(t_data *data);
int		get_current_time(void);
void	*check_win(void *arg);
void	safe_print(t_data *data, int id, const char *action);

#endif