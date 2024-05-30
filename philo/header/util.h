/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:39:46 by stripet           #+#    #+#             */
/*   Updated: 2024/05/30 11:30:49 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "stdlib.h"
# include "../header/structure.h"
# include "stdio.h"
# include "unistd.h"

int		ph_atoi(const char *str);
int		get_current_time(void);
void	safe_print(t_data *data, int id, const char *action);
void	safe_exit(t_data *data);

#endif