/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:28:30 by tienshi           #+#    #+#             */
/*   Updated: 2024/05/27 16:42:42 by stripet          ###   ########.fr       */
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
			safe_print(joe->data, joe->id, "died");
			exit(1);
		}
		usleep((joe->data->time_to_die + 10) * 1000);
	}
}

void	*living(void *arg)
{
	t_philosopher	*joe;
	pthread_t		death_thread;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	joe = arg;
	if (joe->id % 2 == 0)
	{
		first_fork = &joe->left_fork;
		second_fork = &joe->right_fork;
	}
	else
	{
		first_fork = &joe->right_fork;
		second_fork = &joe->left_fork;
	}
	if (pthread_create(&death_thread, NULL, check_death, joe) != 0)
		error(pthread_create_error);
	if (pthread_detach(death_thread) != 0)
		error(pthread_detach_error);
	while (1)
	{
		safe_print(joe->data, joe->id, "is thinking");
		if (pthread_mutex_lock(first_fork) != 0)
			error(pthread_mutex_lock_error);
		safe_print(joe->data, joe->id, "has taken a fork");
		if (pthread_mutex_lock(second_fork) != 0)
			error(pthread_mutex_lock_error);
		safe_print(joe->data, joe->id, "has taken a fork");
		safe_print(joe->data, joe->id, "is eating");
		usleep(joe->data->time_to_eat * 1000);
		joe->last_meal = get_current_time();
		joe->nb_eat++;
		if (pthread_mutex_unlock(&joe->left_fork) != 0)
			error(pthread_mutex_unlock_error);
		if (pthread_mutex_unlock(&joe->right_fork) != 0)
			error(pthread_mutex_unlock_error);
		safe_print(joe->data, joe->id, "is sleeping");
		usleep(joe->data->time_to_sleep * 1000);
	}
}

void	init_philo(t_data *data)
{
	int				i;
	pthread_t		*threads;

	i = 0;
	threads = malloc(sizeof(pthread_t) * data->nb_philo);
	data->boot_time = get_current_time();
	if (!threads)
		error(malloc_error);
	mutex_init(data);
	while (i < data->nb_philo)
	{
		data->philosophers[i].last_meal = get_current_time();
		if (pthread_create(&threads[i], NULL, living,
				&data->philosophers[i]) != 0)
			error(pthread_init_error);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	free(threads);
}

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	they_win;

	if (argc < 5 || argc > 6)
		return (error(bad_args));
	data_init(&data, argv);
	if (argc == 6)
	{
		data.to_win = ph_atoi(argv[5]);
		if (pthread_create(&they_win, NULL, check_win, &data))
			error(pthread_create_error);
		if (pthread_detach(they_win))
			error(pthread_detach_error);
	}
	init_philo(&data);
	return (0);
}
