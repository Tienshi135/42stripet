/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:38:14 by tienshi           #+#    #+#             */
/*   Updated: 2025/08/02 12:21:12 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "controls.h"
#include "mlx.h"
#include "utils.h"

int	close_window(t_data *data)
{
	t_coords	*cursor;

	cursor = data->map->coords;
	while (data->map->coords)
	{
		cursor = data->map->coords->next;
		free(data->map->coords);
		data->map->coords = cursor;
	}
	free(data->map);
	mlx_destroy_window(data->tun_id, data->w_id);
	data->w_id = NULL;
	data->tun_id = NULL;
	exit(1);
	return (0);
}

int	key_press(int key, t_data *data)
{
	if (key == ESC)
		close_window(data);
	else if (key == ARROW_UP)
		data->camera.alpha -= 5;
	else if (key == ARROW_DOWN)
		data->camera.alpha += 5;
	else if (key == ARROW_LEFT)
		data->camera.beta -= 5;
	else if (key == ARROW_RIGHT)
		data->camera.beta += 5;
	else if (key == W)
		data->camera.offsety -= 5;
	else if (key == S)
		data->camera.offsety += 5;
	else if (key == A)
		data->camera.offsetx -= 5;
	else if (key == D)
		data->camera.offsetx += 5;
	else if (key == I)
		data->camera.mode = ISOMETRIC;
	else if (key == C)
		data->camera.mode = CAVALIER;
	else if (key == R)
		reset(data);
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	int	deltax;
	int	deltay;

	if (data->mouse.hook_enable == 0)
		return (1);
	else
	{
		deltax = x - data->mouse.x;
		deltay = y - data->mouse.y;
		if (deltax < 0)
			data->camera.gamma += 1;
		if (deltax > 0)
			data->camera.gamma -= 1;
		if (deltay < 0)
			data->camera.alpha -= 1;
		if (deltay > 0)
			data->camera.alpha += 1;
		data->mouse.x = x;
		data->mouse.y = y;
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_data *data)
{
	if (button == LEFT_CLICK)
		data->mouse.hook_enable = 0;
	return (x + y);
}

int	mouse_press(int button, int x, int y, t_data *data)
{
	if (button == SCROLL_UP && data->camera.zoom <= __FLT_MAX__)
		data->camera.zoom += 0.5;
	else if (button == SCROLL_DOWN && data->camera.zoom >= 0.5)
		data->camera.zoom -= 0.5;
	if (button == LEFT_CLICK)
	{
		if ((x > 70 + 1920 / 16 && y > 740 + 1080 / 8)
			&& (x < 130 + 1920 / 16 && y < 780 + 1080 / 8))
		{
			reset(data);
		}
		else if ((x > 1920 / 4 && y > 1080 / 4)
			&& (x < 3 * (1920 / 4) && y < 3 * (1080 / 4)))
		{
			data->mouse.x = x;
			data->mouse.y = y;
			data->mouse.hook_enable = 1;
		}
	}
	return (0);
}
