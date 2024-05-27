/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:34:15 by stripet           #+#    #+#             */
/*   Updated: 2024/05/27 14:17:13 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "sys/time.h"
# include "pthread.h"

typedef struct s_philosopher
{
	int				id;
	int				last_meal;
	int				nb_eat;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	struct s_data	*data;
}	t_philosopher;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				to_win;
	int				boot_time;
	pthread_mutex_t	rubber_chicken;
	t_philosopher	*philosophers;
}	t_data;

#endif