/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:36:44 by stripet           #+#    #+#             */
/*   Updated: 2025/08/02 12:23:33 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include <math.h>
#include "transformations.h"
#include "mlx.h"

static int	lerp_channel(int a, int b, float t)
{
	return ((int)((1.0f - t) * (float)a + t * (float)b));
}

static int	lerp_color(int ca, int cb, float t)
{
	int	r;
	int	g;
	int	b;

	r = lerp_channel((ca >> 16) & 0xFF, (cb >> 16) & 0xFF, t);
	g = lerp_channel((ca >> 8) & 0xFF, (cb >> 8) & 0xFF, t);
	b = lerp_channel(ca & 0xFF, cb & 0xFF, t);
	return ((r << 16) | (g << 8) | b);
}

/*
** Four-stop height gradient: deep navy → ocean blue → sky cyan → white peak.
** Gives clear height distinction without the old integer-overflow yellows.
*/
static int	height_color(int z, int zmin, int zmax)
{
	static const int	stops[4] = {0x001B44, 0x0096C7, 0x48CAE4, 0xFFFFFF};
	float				t;
	float				seg;
	int					idx;

	if (zmin == zmax)
		return (stops[1]);
	t = (float)(z - zmin) / (float)(zmax - zmin);
	if (t < 0.0f)
		t = 0.0f;
	if (t > 1.0f)
		t = 1.0f;
	seg = t * 3.0f;
	idx = (int)seg;
	if (idx >= 3)
		idx = 2;
	return (lerp_color(stops[idx], stops[idx + 1], seg - (float)idx));
}

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
	coords->color = height_color(coords->z, data->map->zmin, data->map->zmax);
	rotate_x(&y1, &z1, data->camera.alpha);
	rotate_y(&x1, &z1, data->camera.beta);
	rotate_z(&x1, &y1, data->camera.gamma);
	if (data->camera.mode == ISOMETRIC)
		iso(coords, x1, y1, z1);
	else if (data->camera.mode == CAVALIER)
		cavalier(coords, x1, y1, z1);
	coords->tx += data->win_w / 4 + data->camera.offsetx;
	coords->ty += data->win_h / 4 + data->camera.offsety;
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
