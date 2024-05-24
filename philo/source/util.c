/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:39:29 by stripet           #+#    #+#             */
/*   Updated: 2024/05/24 14:50:36 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/util.h"

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
}

int	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
