/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:28:30 by tienshi           #+#    #+#             */
/*   Updated: 2024/05/30 15:01:39 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*check_win(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	i = 0;
	while (i < data->nb_philo)
	{
		if (data->philosophers[i].nb_eat < data->to_win)
			i = 0;
		else
			i++;
	}
	safe_print(data, 0, "All philosophers have eaten enough, they win!");
	safe_exit(data);
	return (NULL);
}

void	*check_death(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (get_current_time() - philo->last_meal < philo->data->time_to_die)
		usleep((philo->data->time_to_die - 10) * 1000);
	philo->is_alive = false;
	return (NULL);
}

void	*living(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (pthread_create(&(philo->death_monitor), NULL, check_death, philo) != 0)
		error(pthread_create_error);
	while (philo->is_alive == true)
	{
		take_forks(philo);
		eat(philo);
		drop_forks(philo);
		sleeping(philo);
		safe_print(philo->data, philo->id, "is thinking");
	}
	if (pthread_join(philo->death_monitor, NULL) != 0)
		error(pthread_join_error);
	return (NULL);
}

void	*death_monitor(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;

	while (1)
	{
		i = 0;
		while (i < data->nb_philo)
		{
			if (data->philosophers[i].is_alive == false)
			{
				safe_print(data, data->philosophers[i].id, "died");
				safe_exit(data);
			}
			i++;
		}
		usleep((data->time_to_die / 4) * 1000);
	}
}

void	create_world(t_data *data)
{
	int	i;

	i = 0;
	data->boot_time = get_current_time();
	while (i < data->nb_philo)
	{
		data->philosophers[i].last_meal = data->boot_time;
		if (pthread_create(&(data->philosophers[i].pasta_eater), NULL, living,
				&(data->philosophers[i])) != 0)
			error(pthread_create_error);
		if (pthread_detach(data->philosophers[i].pasta_eater) != 0)
			error(pthread_detach_error);
		i++;
	}
	if (pthread_create(&data->monitor, NULL, death_monitor, data) != 0)
		error(pthread_create_error);
	if (pthread_join(data->monitor, NULL) != 0)
		error(pthread_join_error);
}

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	monitor;

	if (argc < 5 || argc > 6)
		return (printf("Usage : ./philo nb_philo time_to_die time_to_eat \
time_to_sleep [nb_of_time_each_philo_must_eat]\n"));
	init_data(&data, argc, argv);
	if (data.to_win > -1)
	{
		if (pthread_create(&monitor, NULL, check_win, &data) != 0)
			error(pthread_create_error);
		if (pthread_detach(monitor) != 0)
			error(pthread_detach_error);
	}
	create_world(&data);
	return (0);
}
