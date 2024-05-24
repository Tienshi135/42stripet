/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:33:40 by tienshi           #+#    #+#             */
/*   Updated: 2024/05/24 13:47:53 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "../header/structure.h"
# include "stdlib.h"

enum e_error {
	bad_args = -1,
	gettimeofday_error = -2,
	pthread_create_error = -3,
	pthread_join_error = -4,
	pthread_mutex_init_error = -5,
	pthread_mutex_lock_error = -6,
	pthread_mutex_unlock_error = -7,
	malloc_error = -8
}	;

int	error(int code);

#endif
