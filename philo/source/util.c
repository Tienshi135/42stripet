/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:39:29 by stripet           #+#    #+#             */
/*   Updated: 2024/05/27 16:18:12 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/util.h"
#include "../header/error.h"

int	ph_atoi(const char *str)
{
	int		i;
	int		n;
	int		sign;

	i = 0;
	n = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n * sign);
}

void	mutex_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philosophers[i].id = i + 1;
		data->philosophers[i].data = data;
		pthread_mutex_init(&data->philosophers[i].left_fork, NULL);
		pthread_mutex_init(&data->philosophers[i].right_fork, NULL);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		if (i == data->nb_philo - 1)
			data->philosophers[i].right_fork = data->philosophers[0].left_fork;
		else
			data->philosophers[i].right_fork
				= data->philosophers[i + 1].left_fork;
		i++;
	}
	pthread_mutex_init(&data->rubber_chicken, NULL);
}

void	*check_win(void *arg)
{
	t_data	*data;
	int		i;

	data = arg;
	while (1)
	{
		i = 0;
		while (i < data->nb_philo)
		{
			if (data->philosophers[i].nb_eat < data->to_win)
				break ;
			i++;
		}
		if (i == data->nb_philo)
		{
			pthread_mutex_lock(&(data->rubber_chicken));
			printf("All philosophers have eaten %i times\n", data->to_win);
			exit(0);
		}
		usleep((data->time_to_eat / 10) * 1000);
	}
}

int	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	safe_print(t_data *data, int id, const char *action)
{
	pthread_mutex_lock(&(data->rubber_chicken));
	printf("%i %i %s\n", get_current_time() - data->boot_time, id, action);
	pthread_mutex_unlock(&(data->rubber_chicken));
}
