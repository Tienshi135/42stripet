/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:49:58 by stripet           #+#    #+#             */
/*   Updated: 2024/06/10 15:04:07 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/actions.h"

static void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (safe_get_int(&philo->data->run, &philo->data->run_lock) == 0)
		return ;
	safe_print(philo->data, "has taken a fork", philo->id);
	pthread_mutex_lock(philo->right_fork);
	if (safe_get_int(&philo->data->run, &philo->data->run_lock) == 0)
		return ;
	safe_print(philo->data, "has taken a fork", philo->id);
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	if (safe_get_int(&philo->data->run, &philo->data->run_lock) == 0)
		return ;
	safe_print(philo->data, "is eating", philo->id);
	sleep_time(philo->data->t_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	rest(t_philo *philo)
{
	if (safe_get_int(&philo->data->run, &philo->data->run_lock) == 0)
		return ;
	safe_print(philo->data, "is sleeping", philo->id);
	sleep_time(philo->data->t_sleep);
}
