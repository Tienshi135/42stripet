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
	int			*fucknorm;
	t_coords	current;

	ft_bzero(&current, sizeof(t_coords));
	fucknorm = ft_calloc(sizeof(int), 5);
	current.tx = previous->tx;
	current.ty = previous->ty;
	set_bvalues(previous, next, &fucknorm);
	while (current.tx != next->tx || current.ty != next->ty)
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
		draw(&img, current.tx, current.ty,
			get_gradient(previous, next, &current));
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
	title_render(data);
	return (0);
}
