/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:51:41 by stripet           #+#    #+#             */
/*   Updated: 2024/01/29 15:32:24 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_tools.h"
#include "math.h"
#include "structures.h"

#define TORAD(x) (x/(180/M_PI))

/*void	translate_coords(t_data *data, t_list *list)
{
	t_coords	*buffer;
	int			x;
	int			y;
	int			z;
	int			a;

	buffer = list->content;
	x = buffer->x;
	y = buffer->y;
	z = buffer->z;
	buffer->translatex = round((x - y) * cos(TORAD(30))) * data->zoom;
	buffer->translatey = round(-z + (x + y) * sin(TORAD(30))) * data->zoom;
}*/

void	render_background(t_data *data)
{
	int			i;
	int			j;
	char		*pixel;

	i = 0;
	while (i < 1080 / 2)
	{
		j = 0;
		while (j < 1920 / 2)
		{
			pixel = data->img.addr + j
				* (data->img.bpp / 8) + i * data->img.row_len;
			*(int *) pixel = 0xFFFFFF;
			j++;
		}
		++i;
	}
}

/*void	draw_line()
{

}*/
