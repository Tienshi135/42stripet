/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:39:29 by stripet           #+#    #+#             */
/*   Updated: 2024/05/30 12:17:02 by stripet          ###   ########.fr       */
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


void	safe_exit(t_data *data)
{
	pthread_mutex_destroy(&(data->rubber_chicken));
	free(data->philosophers);
	exit(0);
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
