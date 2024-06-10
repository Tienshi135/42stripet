/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:28:21 by stripet           #+#    #+#             */
/*   Updated: 2024/06/10 15:23:58 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils.h"

int	p_atoi(const char *str)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	sleep_time(int time)
{
	int	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}

int	safe_print(t_data *data, char *str, int id)
{
	if (data->run == 0)
		return (0);
	pthread_mutex_lock(&data->print);
	if (data->run == 0)
	{
		pthread_mutex_unlock(&data->print);
		return (0);
	}
	printf(str, get_time() - data->start, id);
	pthread_mutex_unlock(&data->print);
	if (data->run == 0)
		return (0);
	return (1);
}

int	safe_get_int(int *value, pthread_mutex_t *mutex)
{
	int	ret;

	pthread_mutex_lock(mutex);
	ret = *value;
	pthread_mutex_unlock(mutex);
	return (ret);
}

void	safe_set_int(int *value, int new_value, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	*value = new_value;
	pthread_mutex_unlock(mutex);
}
