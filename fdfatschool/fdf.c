/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:54:01 by tienshi           #+#    #+#             */
/*   Updated: 2024/01/29 15:24:45 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_utils.h"
#include "fdf_tools.h"
#include "./minilibx_macos/mlx.h"
#include <fcntl.h>
#include "math.h"

enum {
	ON_DESTROY = 17,
	RED_PIXEL = 0xFF0000,
	BLACK_PIXEL = 0x000000
};

t_data	init(void)
{
	t_data	buffer;

	ft_memset(&buffer, 0, sizeof(t_data));
	buffer.tun_id = mlx_init();
	buffer.w_id = mlx_new_window(buffer.tun_id, 1920, 1080, "Fdf");
	buffer.img.img_id = mlx_new_image(buffer.tun_id, 1920 / 2, 1080 / 2);
	buffer.img.addr = mlx_get_data_addr(buffer.img.img_id, &buffer.img.bpp,
			&buffer.img.row_len, &buffer.img.endian);
	buffer.zoom = 15;
	return (buffer);
}

/*int	fdf(t_data *data)
{
	hav eto do
	return (0);
}*/

int	main(int argc, char **argv)
{
	int		fd;
	t_data	data;

	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_printf("Failed to open. Check if valid or permissions");
			return (1);
		}
		data = init();
		push_coords_to_data(&data, fd);
		//mlx_loop_hook(data.tun_id, &fdf, &data);
		//mlx_key_hook(data.w_id, &key_press, &data);
		mlx_loop(data.tun_id);
		return (1);
	}
	else
	{
		ft_printf("Bad number of arguments, expected 1+, got 0.\n");
		return (1);
	}
}
