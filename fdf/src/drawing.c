/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:38:45 by tienshi           #+#    #+#             */
/*   Updated: 2025/08/02 12:21:41 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "drawing.h"
#include "transformations.h"
#include "gradient.h"
#include "mlx.h"
#include "utils.h"
#include "title.h"

/*
** Liang-Barsky helpers — clip a line segment to the image rectangle before
** running Bresenham, so zoomed-in maps don't iterate millions of off-screen
** pixels.  Works on copies of the coord structs; does not touch originals.
*/

static int	clip_param(float pv, float qv, float *t0, float *t1)
{
	float	r;

	if (pv == 0.0f)
		return (qv >= 0.0f);
	r = qv / pv;
	if (pv < 0.0f)
	{ if (r > *t0) *t0 = r; }
	else
	{ if (r < *t1) *t1 = r; }
	return (*t0 <= *t1);
}

static int	lerp_color_draw(int ca, int cb, float t)
{
	int	r;
	int	g;
	int	b;

	r = (int)((1.0f - t) * (float)((ca >> 16) & 0xFF)
			+ t * (float)((cb >> 16) & 0xFF));
	g = (int)((1.0f - t) * (float)((ca >> 8) & 0xFF)
			+ t * (float)((cb >> 8) & 0xFF));
	b = (int)((1.0f - t) * (float)(ca & 0xFF) + t * (float)(cb & 0xFF));
	return ((r << 16) | (g << 8) | b);
}

/* Returns 0 if the segment is entirely outside the image rect, 1 otherwise.
** On success, p and n are updated to the clipped endpoints (with interpolated
** colors so the gradient is still correct at the new start/end positions). */
static int	clip_liang_barsky(t_img img, t_coords *p, t_coords *n)
{
	float	t0;
	float	t1;
	int		dx;
	int		dy;
	int		c0;
	int		c1;
	int		orig_px;
	int		orig_py;

	t0 = 0.0f;
	t1 = 1.0f;
	dx = n->tx - p->tx;
	dy = n->ty - p->ty;
	if (!clip_param((float)-dx, (float)p->tx, &t0, &t1))
		return (0);
	if (!clip_param((float)dx, (float)(img.img_width - 1 - p->tx), &t0, &t1))
		return (0);
	if (!clip_param((float)-dy, (float)p->ty, &t0, &t1))
		return (0);
	if (!clip_param((float)dy, (float)(img.img_height - 1 - p->ty), &t0, &t1))
		return (0);
	c0 = p->color;
	c1 = n->color;
	orig_px = p->tx;
	orig_py = p->ty;
	n->tx = orig_px + (int)(t1 * (float)dx);
	n->ty = orig_py + (int)(t1 * (float)dy);
	n->color = lerp_color_draw(c0, c1, t1);
	p->tx = orig_px + (int)(t0 * (float)dx);
	p->ty = orig_py + (int)(t0 * (float)dy);
	p->color = lerp_color_draw(c0, c1, t0);
	return (1);
}

void	set_bvalues(t_coords *p, t_coords *n, int **whateverthisis)
{
	(*whateverthisis)[0] = ft_abs(n->tx - p->tx);
	(*whateverthisis)[1] = ft_abs(n->ty - p->ty);
	(*whateverthisis)[2] = 1;
	(*whateverthisis)[3] = 1;
	(*whateverthisis)[4] = (*whateverthisis)[0] - (*whateverthisis)[1];
	if (p->tx > n->tx)
		(*whateverthisis)[2] *= -1;
	if (p->ty > n->ty)
		(*whateverthisis)[3] *= -1;
}

void	bresenham(t_img img, t_coords *previous, t_coords *next)
{
	t_coords	p;
	t_coords	n;
	int			*fucknorm;
	t_coords	current;

	p = *previous;
	n = *next;
	if (!clip_liang_barsky(img, &p, &n))
		return ;
	ft_bzero(&current, sizeof(t_coords));
	fucknorm = ft_calloc(sizeof(int), 5);
	current.tx = p.tx;
	current.ty = p.ty;
	set_bvalues(&p, &n, &fucknorm);
	while (current.tx != n.tx || current.ty != n.ty)
	{
		if (2 * fucknorm[4] > -fucknorm[1])
		{
			fucknorm[4] -= fucknorm[1];
			current.tx += fucknorm[2];
		}
		else if (2 * fucknorm[4] < fucknorm[0])
		{
			fucknorm[4] += fucknorm[0];
			current.ty += fucknorm[3];
		}
		draw(&img, current.tx, current.ty, get_gradient(&p, &n, &current));
	}
	free(fucknorm);
}

void	put_square_button(t_img *img, t_coords *start, int width, int height)
{
	t_coords	buffer;
	t_coords	end;

	ft_bzero(&buffer, sizeof(t_coords));
	ft_bzero(&end, sizeof(t_coords));
	start->color = RED;
	buffer.color = RED;
	end.color = RED;
	buffer.tx = start->tx + width;
	buffer.ty = start->ty;
	bresenham(*img, start, &buffer);
	buffer.tx = start->tx;
	buffer.ty = start->ty + height;
	bresenham(*img, start, &buffer);
	end.tx = start->tx + width;
	end.ty = start->ty + height;
	buffer.tx = start->tx + width;
	buffer.ty = start->ty;
	bresenham(*img, &end, &buffer);
	buffer.tx = start->tx;
	buffer.ty = start->ty + height;
	bresenham(*img, &end, &buffer);
}

void	draw_line_to_img(t_data *data, t_coords *current)
{
	t_coords	*cursor;

	if (current->x < data->map->width)
	{
		project(data, current->next);
		bresenham(data->img, current, current->next);
	}
	if (current->y < data->map->height)
	{
		cursor = current;
		while (cursor->x != current->x || cursor->y != (current->y + 1))
		{
			if (!(cursor->next))
			{
				exit (-1);
			}
			cursor = cursor->next;
		}
		project(data, cursor);
		bresenham(data->img, current, cursor);
	}
}

int	draw_to_img(t_data *data)
{
	t_coords	*cursor;

	if (!data->dirty)
		return (0);
	data->dirty = 0;
	cursor = data->map->coords;
	render_background(data->img, 1920 / 2, 1080 / 2, GREY);
	while (cursor)
	{
		project(data, cursor);
		draw(&(data->img), cursor->tx, cursor->ty, cursor->color);
		draw_line_to_img(data, cursor);
		cursor = cursor->next;
	}
	mlx_put_image_to_window(data->tun_id, data->w_id,
		data->img.img_id, 1920 / 4,
		1080 / 4 + data->menu.yoffset);
	if (data->camera.mode != data->prev_mode)
	{
		title_render(data);
		data->prev_mode = data->camera.mode;
	}
	return (0);
}
