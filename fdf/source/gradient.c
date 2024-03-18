/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:29:35 by stripet           #+#    #+#             */
/*   Updated: 2024/02/06 12:33:56 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gradient.h"

double	percent(int start, int end, int current)
{
	double	place;
	double	distance;

	place = current - start;
	distance = end - start;
	if (distance != 0)
		return (place / distance);
	else
		return (1.0);
}

int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	get_gradient(t_coords *start, t_coords *end, t_coords *current)
{
	double	percentage;
	int		rgb[3];

	if ((end->tx - start->tx) > (end->ty - start->ty))
		percentage = percent(start->tx, end->tx, current->tx);
	else
		percentage = percent(start->ty, end->ty, current->ty);
	rgb[0] = get_light((start->color >> 16) & 0xFF,
			(end->color >> 16) & 0xFF, percentage);
	rgb[1] = get_light((start->color >> 8) & 0xFF,
			(end->color >> 8) & 0xFF, percentage);
	rgb[2] = get_light(start->color & 0xFF, end->color & 0xFF, percentage);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}
