/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:39:29 by stripet           #+#    #+#             */
/*   Updated: 2024/05/23 18:18:33 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/util.h"

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

void	free_philo(t_data *data)
{
	// int i;

	// i = 0;
	// while ((data->tupid_pasta_eaters) + i)
	// {
	// 	free((data->tupid_pasta_eaters + i)->pthread);
	// 	i++;
	// }
	free(data->tupid_pasta_eaters);
}