/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:48:31 by stripet           #+#    #+#             */
/*   Updated: 2024/05/06 13:28:00 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/error_bonus.h"
#include "../../libft/libft.h"

void	error(t_data *data)
{
	if (data->list)
		free(data->list);
	write(STDERR_FILENO, "Error !\n", 8);
	exit (-1);
}
