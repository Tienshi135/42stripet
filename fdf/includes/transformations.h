/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:42:04 by tienshi           #+#    #+#             */
/*   Updated: 2024/02/22 08:33:03 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORMATIONS_H
# define TRANSFORMATIONS_H

# include <math.h>

void	cavalier(t_coords *coords, int x, int y, int z);
void	iso(t_coords *coords, int x, int y, int z);
void	rotate_z(int *x, int *y, float gamma);
void	rotate_y(int *x, int *z, float beta);
void	rotate_x(int *y, int *z, float alpha);

#endif