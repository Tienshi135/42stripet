/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:40:55 by tienshi           #+#    #+#             */
/*   Updated: 2024/02/17 16:18:24 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_H
# define DRAWING_H

int		draw_to_img(t_data *data);
void	bresenham(t_img img, t_coords *previous, t_coords *next);
void	put_square_button(t_img *img, t_coords *start, int width, int height);
void	draw(t_img *img, int x, int y, int color);

#endif