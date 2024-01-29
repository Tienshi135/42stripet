/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:40:38 by tienshi           #+#    #+#             */
/*   Updated: 2024/01/29 15:29:02 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_UTILS_H
# define FDF_UTILS_H

# include "structures.h"

int		push_coords_to_data(t_data *data, int fd);
int		close_window(t_data *data);
void	push_coords_to_img(t_data *data, t_coords_list *coords, int color);
int		key_press(int keycode, t_data *data);

#endif