/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:34:15 by stripet           #+#    #+#             */
/*   Updated: 2024/05/20 15:19:27 by stripet          ###   ########.fr       */
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

typedef struct s_philo
{
	pthread_t 		pthread;
	int				alive;
	int				lfork;
	int 			rfork;
}	t_philo;

typedef struct s_data
{
	struct timeval  time;
	int             nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	int 			forks;
	t_philo			*tupid_pasta_eaters;
}	t_data;

#endif