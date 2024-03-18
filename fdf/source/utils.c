/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:36:44 by stripet           #+#    #+#             */
/*   Updated: 2024/02/27 08:43:09 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structures.h"
#include "../includes/utils.h"
#include <math.h>
#include "../includes/transformations.h"
#include "../minilibx_macos/mlx.h"

double	torad(double x)
{
	return (x / (180.0 / M_PI));
}

void	render_background(t_img img, int width, int height, int color)
{
	int		x;
	int		y;
	char	*pixel;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			pixel = img.addr + x * (img.bpp / 8) + y * img.row_len;
			*(int *)pixel = color;
			x++;
		}
		y++;
	}
}

void	reset(t_data *data)
{
	data->camera.alpha = 0;
	data->camera.beta = 0;
	data->camera.gamma = 0;
	data->camera.offsetx = 0;
	data->camera.offsety = 0;
	data->camera.zoom = 15;
}

void	project(t_data *data, t_coords *coords)
{
	int	x1;
	int	y1;
	int	z1;

	x1 = coords->x;
	y1 = coords->y;
	z1 = coords->z;
	x1 *= data->camera.zoom;
	y1 *= data->camera.zoom;
	z1 *= data->camera.zoom;
	x1 -= (data->map->width * data->camera.zoom) / 2;
	y1 -= (data->map->height * data->camera.zoom) / 2;
	coords->color = (BLACK - (30 * coords->z));
	rotate_x(&y1, &z1, data->camera.alpha);
	rotate_y(&x1, &z1, data->camera.beta);
	rotate_z(&x1, &y1, data->camera.gamma);
	if (data->camera.mode == ISOMETRIC)
		iso(coords, x1, y1, z1);
	else if (data->camera.mode == CAVALIER)
		cavalier(coords, x1, y1, z1);
	coords->tx += 1920 / 4 + data->camera.offsetx;
	coords->ty += 1080 / 4 + data->camera.offsety;
}

void	draw(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if ((x < 0 || y < 0) || (x > img->img_width - 1 || y > img->img_height - 1))
		return ;
	pixel = img->addr + x
		* (img->bpp / 8) + y * img->row_len;
	*(int *) pixel = color;
}
