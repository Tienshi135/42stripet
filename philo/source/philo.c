/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:28:30 by tienshi           #+#    #+#             */
/*   Updated: 2024/05/20 15:32:04 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

#include "stdio.h"

void	data_init(t_philo *data, char **argv)
{
	memset(data, 0, sizeof(t_philo));
	data->nb_philo = ph_atoi(argv[1]);
	data->time_to_die = ph_atoi(argv[2]);
	data->time_to_eat = ph_atoi(argv[3]);
	data->time_to_sleep = ph_atoi(argv[4]);
	if (gettimeofday(&data->time, NULL) == -1)
		error(gettimeofday_error);
	data->philo_threads = malloc(sizeof(pthread_t *) * data->nb_philo);
}

void	*philo(void *arg)
{
	(void)arg;
	printf("hello from thread philo %i\n", *(int *)arg);
	return (NULL);
}

void	init_philo(t_philo *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philo_threads[i] = malloc(sizeof(pthread_t));
		if (pthread_create((data->philo_threads)[i], NULL, &philo, &i) != 0)
			error(pthread_create_error);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_philo	data;

	if (argc < 5 || argc > 6)
		return (error(bad_args));
	data_init(&data, argv);
	if (argc == 6)
		data.nb_eat = ph_atoi(argv[5]);
	init_philo(&data);
	return (0);
}
