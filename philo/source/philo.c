/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:04:14 by stripet           #+#    #+#             */
/*   Updated: 2024/06/10 15:36:44 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	philo_init(t_data *data, char **argv)
{
	int	i;

	i = 0;
	data->nb_philo = p_atoi(argv[1]);
	data->t_die = p_atoi(argv[2]);
	data->t_eat = p_atoi(argv[3]);
	data->t_sleep = p_atoi(argv[4]);
	data->nb_eat = -1;
	while (i < data->nb_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].data = data;
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		data->philo[i].left_fork = &data->forks[i];
		data->philo[i].right_fork = &data->forks[(i + 1) % data->nb_philo];
		i++;
	}
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->run_lock, NULL);
}

void	*death_monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	while (1)
	{
		if (safe_get_int(&philo->data->run, &philo->data->run_lock) == 0)
			return (NULL);
		if (get_time() - philo->last_meal > philo->data->t_die)
		{
			safe_set_int(&philo->data->run, 0, &philo->data->run_lock);
			printf("%d Philo %d died\n", get_time(), philo->id);
			return (NULL);
		}
		sleep_time(10);
	}
	return (NULL);
}

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_create(&philo->death_monitor, NULL, &death_monitor, philo);
	while (1)
	{
		if (!safe_print(philo->data, "%d Philo %d is thinking\n", philo->id))
			return (NULL);
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(philo->left_fork);
			if (!safe_print(philo->data, "%d Philo %d has taken a fork\n", philo->id))
				return (NULL);
			pthread_mutex_lock(philo->right_fork);
		}
		else
		{
			pthread_mutex_lock(philo->right_fork);
			if (!safe_print(philo->data, "%d Philo %d has taken a fork\n", philo->id))
				return (NULL);
			pthread_mutex_lock(philo->left_fork);
		}
		if (!safe_print(philo->data, "%d Philo %d has taken a fork\n", philo->id))
			return (NULL);
		if (!safe_print(philo->data, "%d Philo %d is eating\n", philo->id))
			return (NULL);
		philo->last_meal = get_time();
		sleep_time(philo->data->t_eat);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		if (!safe_print(philo->data, "%d Philo %d is sleeping\n", philo->id))
			return (NULL);
		sleep_time(philo->data->t_sleep);
	}
	pthread_join(philo->death_monitor, NULL);
	return (NULL);
}

void	create_world(t_data *data)
{
	int	i;

	i = 0;
	data->run = 1;
	data->start = get_time();
	while (i < data->nb_philo)
	{
		data->philo[i].last_meal = get_time();
		pthread_create(&data->philo[i].thread, NULL,
			&philo_life, &data->philo[i]);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5)
	{
		printf("Usage: %s [nb_philo] [t_die] [t_eat] [t_sleep] \n", argv[0]);
		return (1);
	}
	data.philo = malloc(sizeof(t_philo) * p_atoi(argv[1]));
	data.forks = malloc(sizeof(pthread_mutex_t) * p_atoi(argv[1]));
	philo_init(&data, argv);
	create_world(&data);
	free(data.philo);
	free(data.forks);
	return (0);
}
