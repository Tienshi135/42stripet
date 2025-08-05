/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:13:19 by tienshi           #+#    #+#             */
/*   Updated: 2025/08/02 12:23:08 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "title.h"
#include "mlx.h"
#include "utils.h"

void	title_render(t_data *data)
{
	render_background(data->title, data->title.img_width,
		data->title.img_height, WHITE);
	mlx_put_image_to_window(data->tun_id, data->w_id,
		data->title.img_id, 1920 / 4, (1080 / 4 - 80) / 2);
	mlx_string_put(data->tun_id, data->w_id,
		1920 / 4 + (1920 / 2 - 10 * 10) / 2, (1080 / 4 - 80) / 2,
		BLACK, "Fil De Fer");
	if (data->camera.mode == ISOMETRIC)
	{
		mlx_string_put(data->tun_id, data->w_id,
			1920 / 4 + (1920 / 2 - 10 * 23) / 2, (1080 / 4 - 80) / 2 + 40,
			BLACK, "In Isometric projection");
	}
	else if (data->camera.mode == CAVALIER)
	{
		mlx_string_put(data->tun_id, data->w_id,
			1920 / 4 + (1920 / 2 - 10 * 22) / 2, (1080 / 4 - 80) / 2 + 40,
			BLACK, "In Cavalier projection");
	}
}

void	title_init(t_data *data)
{
	ft_memset(&(data->title), 0, sizeof(t_img));
	data->title.img_width = 1920 / 2;
	data->title.img_height = 80;
	data->title.img_id = mlx_new_image(data->tun_id,
			data->title.img_width, data->title.img_height);
	data->title.addr = mlx_get_data_addr(data->title.img_id,
			&(data->title.bpp), &(data->title.row_len),
			&(data->title.endian));
	title_render(data);
}
