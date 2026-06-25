/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:39:55 by tienshi           #+#    #+#             */
/*   Updated: 2025/08/01 09:21:52 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_fps(t_fps *fps)
{
	fps->frame_count = 0;
	fps->fps = 0.0f;
	fps->fps_text[0] = '\0';
	clock_gettime(CLOCK_MONOTONIC, &fps->last_time);
}

void	update_fps(t_fps *fps)
{
	struct timespec	now;
	double			elapsed;

	fps->frame_count++;
	if (fps->frame_count < 30)
		return ;
	clock_gettime(CLOCK_MONOTONIC, &now);
	elapsed = (double)(now.tv_sec - fps->last_time.tv_sec)
		+ (double)(now.tv_nsec - fps->last_time.tv_nsec) * 1e-9;
	if (elapsed > 0.0)
	{
		fps->fps = (float)(fps->frame_count) / (float)elapsed;
		snprintf(fps->fps_text, sizeof(fps->fps_text), "FPS: %.0f", fps->fps);
	}
	fps->frame_count = 0;
	fps->last_time = now;
}

void	draw_fps(t_data *data)
{
	if (data->fps->fps_text[0] != '\0')
		mlx_string_put(data->mlx->mlx_tunnel, data->mlx->window,
			10, 20, WHITE, data->fps->fps_text);
}
