/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:28:30 by tienshi           #+#    #+#             */
/*   Updated: 2024/05/23 18:17:15 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	data_init(t_data *data, char **argv)
{
	memset(data, 0, sizeof(t_data));
	data->nb_philo = ph_atoi(argv[1]);
	data->time_to_die = ph_atoi(argv[2]);
	data->time_to_eat = ph_atoi(argv[3]);
	data->time_to_sleep = ph_atoi(argv[4]);
	if (gettimeofday(&data->time, NULL) == -1)
		error(gettimeofday_error);
	data->tupid_pasta_eaters = malloc(sizeof(pthread_t *) * data->nb_philo);
	data->forks = data->nb_philo;
}

void	*philo(void *arg)
{
	struct timeval	time;
	t_data			*buffer;

	gettimeofday(&time, NULL);
	buffer = (t_data *) arg;
	(void)arg;
	printf("Time since start : %d", buffer->time.tv_usec - time.tv_usec);
	return (NULL);
}

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		(data->tupid_pasta_eaters + i)->pthread = malloc(sizeof(pthread_t));
		if (pthread_create(&(data->tupid_pasta_eaters + i)->pthread, NULL, &philo, data) != 0)
			error(pthread_create_error);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join((data->tupid_pasta_eaters + i)->pthread, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (error(bad_args));
	data_init(&data, argv);
	if (argc == 6)
		data.nb_eat = ph_atoi(argv[5]);
	init_philo(&data);
	free_philo(&data);
	return (0);
}
