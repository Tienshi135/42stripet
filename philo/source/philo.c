/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:28:30 by tienshi           #+#    #+#             */
/*   Updated: 2024/05/24 15:26:45 by stripet          ###   ########.fr       */
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
	data->philosophers = malloc(sizeof(t_philosopher) * data->nb_philo);
}

void	*check_death(void *arg)
{
	t_philosopher	*joe;

	joe = arg;
	while (1)
	{
		if (get_current_time() - joe->last_meal > joe->data->time_to_die)
		{
			printf("Philosopher %d died\n", joe->id);
			exit(0);
		}
		usleep(joe->data->time_to_die + 1);
	}
}

void	*living(void *arg)
{
	t_philosopher	*joe;
	pthread_t		death_thread;

	joe = arg;
	pthread_create(&death_thread, NULL, check_death, joe);
	pthread_detach(death_thread);
	while (1)
	{
		printf("Philosopher %d is thinking\n", joe->id);
		if (pthread_mutex_lock(&joe->left_fork) != 0)
			error(pthread_mutex_lock_error);
		if (pthread_mutex_lock(&joe->right_fork) != 0)
			error(pthread_mutex_lock_error);
		printf("Philosopher %d is eating\n", joe->id);
		usleep(joe->data->time_to_eat * 1000);
		joe->last_meal = get_current_time();
		if (pthread_mutex_unlock(&joe->left_fork) != 0)
			error(pthread_mutex_unlock_error);
		if (pthread_mutex_unlock(&joe->right_fork) != 0)
			error(pthread_mutex_unlock_error);
		printf("Philosopher %d is sleeping\n", joe->id);
		usleep(joe->data->time_to_sleep * 1000);
	}
}

void	init_philo(t_data *data)
{
	int				i;
	pthread_t		*threads;

	i = 0;
	threads = malloc(sizeof(pthread_t) * data->nb_philo);
	if (!threads)
		error(malloc_error);
	mutex_init(data);
	while (i < data->nb_philo)
	{
		data->philosophers[i].last_meal = get_current_time();
		if (pthread_create(&threads[i], NULL, living,
				&data->philosophers[i]) != 0)
			error(pthread_create_error);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(threads[i], NULL) != 0)
			error(pthread_join_error);
		i++;
	}
	free(threads);
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
	return (0);
}
