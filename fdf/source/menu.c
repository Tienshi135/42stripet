/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:05:44 by tienshi           #+#    #+#             */
/*   Updated: 2024/02/22 08:26:14 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/menu.h"
#include "../minilibx_macos/mlx.h"
#include "../libft/libft.h"
#include "../includes/drawing.h"
#include "../includes/utils.h"

void	line(t_data *data, int x1, int x2, int y)
{
	t_coords	point1;
	t_coords	point2;

	ft_bzero(&point1, sizeof(t_coords));
	ft_bzero(&point2, sizeof(t_coords));
	point1.tx = x1;
	point1.ty = y;
	point1.color = RED;
	point2.tx = x2;
	point2.ty = y;
	point2.color = RED;
	bresenham(data->menu.img, &point1, &point2);
}

void	reset_button(t_data *data, int width, int height)
{
	t_coords	position;
	int			x;
	int			y;

	ft_bzero(&position, sizeof(t_coords));
	position.tx = 70;
	position.ty = 740;
	y = position.ty + 1;
	while (y < position.ty + height - 1)
	{
		x = position.tx + 1;
		while (x < position.tx + width - 1)
		{
			draw(&(data->menu.img), x, y, WHITE);
			x++;
		}
		y++;
	}
	put_square_button(&(data->menu.img), &position, width, height);
}

void	menu_draw(t_data *data)
{
	mlx_string_put(data->tun_id, data->w_id, (200 - (char_width * 10))
		/ 2 + 1920 / 16, 150, WHITE, "How To Use");
	mlx_string_put(data->tun_id, data->w_id, (200 - (char_width * 16))
		/ 2 + 1920 / 16, 190, WHITE, "Use WASD to move");
	mlx_string_put(data->tun_id, data->w_id, (200 - (char_width * 18))
		/ 2 + 1920 / 16, 230, WHITE, "Use scroll to zoom");
	mlx_string_put(data->tun_id, data->w_id, (200 - (char_width * 19))
		/ 2 + 1920 / 16, 270, WHITE, "Use arrows or click");
	mlx_string_put(data->tun_id, data->w_id, (200 - (char_width * 18))
		/ 2 + 1920 / 16, 290, WHITE, "and drag to rotate");
	mlx_string_put(data->tun_id, data->w_id, (200 - (char_width * 14))
		/ 2 + 1920 / 16, 330, WHITE, "use r to reset");
	mlx_string_put(data->tun_id, data->w_id, (200 - (char_width * 20))
		/ 2 + 1920 / 16, 370, WHITE, "use i/c to swap view");
	mlx_string_put(data->tun_id, data->w_id, (200 - (char_width * 5))
		/ 2 + 1920 / 16, 1080 / 8 + 10 + 740, GREY, "Reset");
}

void	menu_init(t_data *data)
{
	ft_memset(&(data->menu.img), 0, sizeof(t_img));
	data->menu.img.img_width = 200;
	data->menu.img.img_height = 800;
	data->menu.img.img_id = mlx_new_image(data->tun_id, 200, 800);
	data->menu.img.addr = mlx_get_data_addr(data->menu.img.img_id,
			&(data->menu.img.bpp), &(data->menu.img.row_len),
			&(data->menu.img.endian));
	render_background(data->menu.img, 200, 800, GREY);
	line(data, 20, 180, 45);
	line(data, 20, 180, 285);
	reset_button(data, 60, 40);
	mlx_put_image_to_window(data->tun_id, data->w_id,
		data->menu.img.img_id, 1920 / 16, 1080 / 8);
	menu_draw(data);
}
