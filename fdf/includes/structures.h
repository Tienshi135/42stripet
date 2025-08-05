/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:45:47 by tienshi           #+#    #+#             */
/*   Updated: 2025/08/02 14:59:14 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "libft.h"
# include <stdio.h>

enum {
	WHITE = 0xFFFFFF,
	BLACK = 0x000000,
	RED = 0xFF0000,
	GREY = 0x808080
};

enum {
	ISOMETRIC = 0,
	CAVALIER = 1
};

typedef struct s_coords {
	int				x;
	int				y;
	int				z;
	int				tx;
	int				ty;
	int				color;
	struct s_coords	*next;
}	t_coords;

typedef struct s_mouse {
	int			x;
	int			y;
	int			hook_enable;
	t_coords	reset_button;
}	t_mouse;

typedef struct s_map {
	int			height;
	int			width;
	t_coords	*coords;
}	t_map;

typedef struct s_img{
	void		*img_id;
	char		*addr;
	int			bpp;
	int			row_len;
	int			endian;
	int			img_width;
	int			img_height;
}	t_img;

typedef struct s_menu {
	int		xoffset;
	int		yoffset;
	t_img	img;
}	t_menu;

typedef struct s_camera{
	float	zoom;
	double	alpha;
	double	beta;
	double	gamma;
	int		offsetx;
	int		offsety;
	int		mode;
}	t_camera;

typedef struct s_data {
	void		*w_id;
	void		*tun_id;
	t_img		img;
	t_map		*map;
	t_camera	camera;
	t_mouse		mouse;
	t_menu		menu;
	t_img		title;
}	t_data;

#endif