/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:33:40 by tienshi           #+#    #+#             */
/*   Updated: 2024/05/20 14:12:25 by stripet          ###   ########.fr       */
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
	return (code);
}
