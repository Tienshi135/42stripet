/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:37:30 by tienshi           #+#    #+#             */
/*   Updated: 2024/02/22 13:38:41 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structures.h"
#include "../minilibx_macos/mlx.h"
#include "../includes/mapping.h"
#include "../includes/hooks.h"
#include <fcntl.h>
#include "../includes/menu.h"
#include "../includes/title.h"
#include "../includes/fdf.h"

void	split_free(char **tofree)
{
	int	i;

	i = 0;
	while (tofree[i])
	{
		free(tofree[i]);
		i++;
	}
	free(tofree);
}

t_data	init(void)
{
	t_data	buffer;

	ft_memset(&buffer, 0, sizeof(t_data));
	buffer.tun_id = mlx_init();
	buffer.w_id = mlx_new_window(buffer.tun_id, 1920, 1080, "Fdf");
	buffer.img.img_id = mlx_new_image(buffer.tun_id, 1920 / 2, 1080 / 2);
	buffer.img.img_width = 1920 / 2;
	buffer.img.img_height = 1080 / 2;
	buffer.img.addr = mlx_get_data_addr(buffer.img.img_id, &buffer.img.bpp,
			&buffer.img.row_len, &buffer.img.endian);
	buffer.camera.zoom = 15;
	buffer.camera.alpha = 0;
	buffer.camera.beta = 0;
	buffer.camera.gamma = 0;
	buffer.camera.offsetx = 0;
	buffer.camera.offsety = 0;
	buffer.mouse.hook_enable = 0;
	buffer.camera.mode = ISOMETRIC;
	menu_init(&buffer);
	title_init(&buffer);
	return (buffer);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror("Error opening file");
			return (1);
		}
		data = init();
		data.map = read_map(fd);
		if (!(data.map->coords))
			exit (-2);
		if (!data.map)
			return (1);
		hook_init(data);
		return (0);
	}
	else
		ft_printf("Bad numbers of arguments, expected 1, got %i\n", argc - 1);
	return (1);
}
