/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_tools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:54:37 by stripet           #+#    #+#             */
/*   Updated: 2024/01/25 13:32:48 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_TOOLS_H
# define FDF_TOOLS_H

# include "structures.h"

void	translate_coords(t_data *data, t_list *list);
void	render_background(t_data *data);
void	draw_line(t_data *data, t_list *prev, t_list *current, int color);

#endif