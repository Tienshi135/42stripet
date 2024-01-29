/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:07:14 by tienshi           #+#    #+#             */
/*   Updated: 2024/01/29 15:00:56 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "./libft/libft.h"

typedef struct coords{
	int				x;
	int				y;
	int				z;
	int				translatex;
	int				translatey;
	struct coords	*next;
	struct coords	*previous;
}	t_coords_list;

typedef struct img{
	void		*img_id;
	char		*addr;
	int			bpp;
	int			row_len;
	int			endian;
}	t_img;

typedef struct data{
	void			*w_id;
	void			*tun_id;
	t_img			img;
	t_coords_list	*list;
	int				zoom;
}	t_data;

#endif
