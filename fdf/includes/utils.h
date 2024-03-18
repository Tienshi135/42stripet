/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:37:10 by stripet           #+#    #+#             */
/*   Updated: 2024/02/22 08:34:48 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../includes/structures.h"

double	torad(double x);
void	render_background(t_img img, int width, int height, int color);
void	reset(t_data *data);
void	project(t_data *data, t_coords *coords);
void	draw(t_img *img, int x, int y, int color);

#endif