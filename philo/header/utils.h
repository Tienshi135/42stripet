/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:28:09 by stripet           #+#    #+#             */
/*   Updated: 2024/06/10 15:23:14 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structures.h"
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>

int		p_atoi(const char *str);
int		get_time(void);
void	sleep_time(int time);
int		safe_print(t_data *data, char *str, int id);
int		safe_get_int(int *value, pthread_mutex_t *mutex);
void	safe_set_int(int *value, int new_value, pthread_mutex_t *mutex);

#endif