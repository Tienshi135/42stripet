/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:34:15 by stripet           #+#    #+#             */
/*   Updated: 2024/05/24 14:53:14 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "sys/time.h"
# include "pthread.h"

enum e_bool
{
	True = 1,
	False = 0
}	;

typedef struct s_philosopher
{
	int				id;
	int				last_meal;
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
	int				nb_eat;
	t_philosopher	*philosophers;
}	t_data;

#endif