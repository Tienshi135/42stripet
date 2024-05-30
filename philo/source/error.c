/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:33:40 by tienshi           #+#    #+#             */
/*   Updated: 2024/05/30 11:20:26 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/error.h"
#include "stdio.h"

int	error(int code)
{
	if (code == gettimeofday_error)
		printf("Error : gettimeofday\n");
	else if (code == pthread_create_error)
		printf("Error : pthread_init\n");
	else if (code == pthread_join_error)
		printf("Error : pthread_join\n");
	else if (code == pthread_detach_error)
		printf("Error : pthread_detach\n");
	else if (code == pthread_mutex_init_error)
		printf("Error : pthread_mutex_init\n");
	else if (code == pthread_mutex_lock_error)
		printf("Error : pthread_mutex_lock\n");
	else if (code == pthread_mutex_unlock_error)
		printf("Error : pthread_mutex_unlock\n");
	return (code);
}
