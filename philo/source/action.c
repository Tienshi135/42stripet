/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:54:34 by stripet           #+#    #+#             */
/*   Updated: 2024/05/30 14:51:21 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/action.h"

void	take_forks(t_philosopher *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (philo->id % 2 == 0)
	{
		first = philo->right_fork;
		second = philo->left_fork;
	}
	else
	{
		first = philo->left_fork;
		second = philo->right_fork;
	}
	pthread_mutex_lock(first);
	safe_print(philo->data, philo->id, "has taken a fork");
	pthread_mutex_lock(second);
	safe_print(philo->data, philo->id, "has taken a fork");
}

void	eat(t_philosopher *philo)
{
	philo->last_meal = get_current_time();
	safe_print(philo->data, philo->id, "is eating");
	usleep(philo->data->time_to_eat * 1000);
	philo->nb_eat++;
}

void	drop_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleeping(t_philosopher *philo)
{
	safe_print(philo->data, philo->id, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
}
