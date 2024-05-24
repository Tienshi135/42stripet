/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:33:40 by tienshi           #+#    #+#             */
/*   Updated: 2024/05/24 13:47:48 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/error.h"
#include "stdio.h"

int	error(int code)
{
	if (code == bad_args)
		printf("Error: bad arguments; usage : ./philo number_of_philosophers time_to_die time_to_eat\
 time_to_sleep [number_of_time_each_philosophers_must_eat]\n");
	else if (code == gettimeofday_error)
		printf("Error: gettimeofday failed\n");
	else if (code == pthread_create_error)
		printf("Error: pthread_create failed\n");
	else if (code == pthread_join_error)
		printf("Error: pthread_join failed\n");
	else if (code == pthread_mutex_init_error)
		printf("Error: pthread_mutex_init failed\n");
	else if (code == pthread_mutex_lock_error)
		printf("Error: pthread_mutex_lock failed\n");
	else if (code == pthread_mutex_unlock_error)
		printf("Error: pthread_mutex_unlock failed\n");
	else if (code == malloc_error)
		printf("Error: malloc failed\n");
	return (code);
}
