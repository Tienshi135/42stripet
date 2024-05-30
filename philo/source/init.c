/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:35:13 by stripet           #+#    #+#             */
/*   Updated: 2024/05/30 14:12:00 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/init.h"

static void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philosophers[i].data = data;
		data->philosophers[i].id = i + 1;
		data->philosophers[i].nb_eat = 0;
		data->philosophers[i].is_alive = true;
		data->philosophers[i].left_fork = malloc(sizeof(pthread_mutex_t));
		data->philosophers[i].right_fork = malloc(sizeof(pthread_mutex_t));
		if (pthread_mutex_init(data->philosophers[i].left_fork, NULL) != 0)
			error(pthread_mutex_init_error);
		if (pthread_mutex_init(data->philosophers[i].right_fork, NULL) != 0)
			error(pthread_mutex_init_error);
		i++;
	}
	i = -1;
	while (++i < data->nb_philo)
	{
		if (i == data->nb_philo - 1)
			data->philosophers[i].right_fork = data->philosophers[0].left_fork;
		else
			data->philosophers[i].right_fork = data->philosophers[i + 1].left_fork;
	}
}

void	init_data(t_data *data, int argc, char **argv)
{
	data->nb_philo = ph_atoi(argv[1]);
	data->time_to_die = ph_atoi(argv[2]);
	data->time_to_eat = ph_atoi(argv[3]);
	data->time_to_sleep = ph_atoi(argv[4]);
	data->to_win = -1;
	if (argc == 6)
		data->to_win = ph_atoi(argv[5]);
	data->philosophers = malloc(sizeof(t_philosopher) * data->nb_philo);
	if (!data->philosophers)
		exit(-14);
	if (pthread_mutex_init(&(data->rubber_chicken), NULL) != 0)
		error(pthread_mutex_init_error);
	init_philo(data);
}
