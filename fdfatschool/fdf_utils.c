/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:38:00 by tienshi           #+#    #+#             */
/*   Updated: 2024/01/29 15:36:51 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "fdf_utils.h"
#include <stdio.h>
#include "control.h"
#include "fdf_tools.h"

enum {
	ESC = 53,
	ARROW_UP = 126,
	ARROW_DOWN = 125,
	ARROW_LEFT = 123,
	ARROW_RIGHT = 124
};

int	close_window(t_data *data)
{
	mlx_destroy_window(data->tun_id, data->w_id);
	data->w_id = NULL;
	//ft_lstclear(&(data->list), &free);
	ft_printf("All worked good !");
	exit (0);
	return (0);
}

t_coords_list	*ft_clstlast(t_coords_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_clstadd_back(t_coords_list **lst, t_coords_list *new)
{
	t_coords_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_clstlast(*lst);
	last->next = new;
	new->previous = last;
}

void	push_coords_to_struct(t_data **data, int x, int y, int z)
{
	t_coords_list	*buffer;

	buffer = ft_calloc(1, sizeof(t_coords_list));
	buffer->x = x + 1;
	buffer->y = y;
	buffer->z = z;
	ft_clstadd_back(&((*data)->list), buffer);
}

int	push_coords_to_data(t_data *data, int fd)
{
	char	*line;
	char	**buffer;
	int		x;
	int		y;
	int		i;

	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		x = 0;
		buffer = ft_split(line, ' ');
		while (buffer[i])
		{
			push_coords_to_struct(&data, x++, y, ft_atoi(buffer[i]));
			i++;
		}
		free(buffer);
		line = get_next_line(fd);
		y++;
	}
	return (0);
}

/*void	push_coords_to_img(t_data *data, t_coords_list *coords, int color)
{

}*/
