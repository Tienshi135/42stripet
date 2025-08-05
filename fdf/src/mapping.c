/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:38:17 by tienshi           #+#    #+#             */
/*   Updated: 2025/08/02 12:22:41 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "mapping.h"
#include "fdf.h"

int	to_coords(t_map *map, int x, int y, int z)
{
	t_coords	*buffer;
	t_coords	*cursor;

	buffer = ft_calloc(1, sizeof(t_coords));
	if (!buffer)
		return (1);
	buffer->x = x;
	buffer->y = y;
	buffer->z = z;
	buffer->next = NULL;
	if (!map->coords)
		map->coords = buffer;
	else
	{
		cursor = map->coords;
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = buffer;
	}
	return (0);
}

t_map	*read_map(int fd)
{
	t_map	*map;
	char	*line;
	char	**buffer;

	line = get_next_line(fd);
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	while (line)
	{
		map->width = 0;
		map->height++;
		buffer = ft_split(line, ' ');
		while (buffer[map->width])
		{
			if (to_coords(map, map->width + 1,
					map->height, ft_atoi(buffer[map->width])) == 1)
				return (NULL);
			map->width++;
		}
		split_free(buffer);
		free(line);
		line = get_next_line(fd);
	}
	return (map);
}
