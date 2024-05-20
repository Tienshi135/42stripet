/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:33:40 by tienshi           #+#    #+#             */
/*   Updated: 2024/05/20 14:12:18 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

enum e_error {
	bad_args = -1,
	gettimeofday_error = -2,
	pthread_create_error = -3
}	;

int	error(int code);

#endif