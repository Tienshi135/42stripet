/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:56:43 by tienshi           #+#    #+#             */
/*   Updated: 2024/02/22 08:31:09 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structures.h"
#include "../includes/transformations.h"
#include "../includes/utils.h"

void	rotate_x(int *y, int *z, float alpha)
{
	int	previous_y;

	previous_y = *y;
	*y = previous_y * cos(torad(alpha)) + *z * sin(torad(alpha));
	*z = -previous_y * sin(torad(alpha)) + *z * cos(torad(alpha));
}

void	rotate_y(int *x, int *z, float beta)
{
	int	previous_x;

	previous_x = *x;
	*x = previous_x * cos(torad(beta)) + *z * sin(torad(beta));
	*z = -previous_x * sin(torad(beta)) + *z * cos(torad(beta));
}

void	rotate_z(int *x, int *y, float gamma)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(torad(gamma)) - previous_y * sin(torad(gamma));
	*y = previous_x * sin(torad(gamma)) + previous_y * cos(torad(gamma));
}

void	iso(t_coords *coords, int x, int y, int z)
{
	coords->tx = (x - y) * cos(torad(30));
	coords->ty = -z + (x + y) * sin(torad(30));
}

void	cavalier(t_coords *coords, int x, int y, int z)
{
	coords->tx = x + z * cos(torad(45));
	coords->ty = y + z * sin(torad(45));
}
