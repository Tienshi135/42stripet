/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:34:15 by stripet           #+#    #+#             */
/*   Updated: 2024/05/30 14:05:23 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "sys/time.h"
# include "pthread.h"

typedef enum e_bool{
	true,
	false
}	t_bool;

typedef struct s_philosopher
{
	struct s_data	*data;
	int				id;
	int				last_meal;
	int				nb_eat;
	t_bool			is_alive;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		death_monitor;
	pthread_t		pasta_eater;
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
	pthread_t		monitor;
	t_philosopher	*philosophers;
}	t_data;

#endif