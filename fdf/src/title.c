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
	int	tx;
	int	ty;

	tx = data->win_w / 4;
	ty = (data->win_h / 4 - 80) / 2;
	render_background(data->title, data->title.img_width,
		data->title.img_height, WHITE);
	mlx_put_image_to_window(data->tun_id, data->w_id,
		data->title.img_id, tx, ty);
	mlx_string_put(data->tun_id, data->w_id,
		tx + (data->win_w / 2 - 10 * 10) / 2, ty + 20,
		BLACK, "Fil De Fer");
	if (data->camera.mode == ISOMETRIC)
		mlx_string_put(data->tun_id, data->w_id,
			tx + (data->win_w / 2 - 10 * 23) / 2, ty + 60,
			BLACK, "In Isometric projection");
	else if (data->camera.mode == CAVALIER)
		mlx_string_put(data->tun_id, data->w_id,
			tx + (data->win_w / 2 - 10 * 22) / 2, ty + 60,
			BLACK, "In Cavalier projection");
}

void	title_init(t_data *data)
{
	ft_memset(&(data->title), 0, sizeof(t_img));
	data->title.img_width = data->win_w / 2;
	data->title.img_height = 80;
	data->title.img_id = mlx_new_image(data->tun_id,
			data->title.img_width, data->title.img_height);
	data->title.addr = mlx_get_data_addr(data->title.img_id,
			&(data->title.bpp), &(data->title.row_len),
			&(data->title.endian));
	title_render(data);
}
