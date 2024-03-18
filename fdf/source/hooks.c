/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:54:57 by stripet           #+#    #+#             */
/*   Updated: 2024/02/16 18:11:00 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structures.h"
#include "../includes/hooks.h"
#include "../includes/drawing.h"
#include "../includes/controls.h"
#include "../minilibx_macos/mlx.h"

void	hook_init(t_data data)
{
	mlx_hook(data.w_id, ON_DESTROY, 0, &close_window, &data);
	mlx_hook(data.w_id, KEY_PRESS, 0, &key_press, &data);
	mlx_hook(data.w_id, MOUSE_PRESS, 0, &mouse_press, &data);
	mlx_hook(data.w_id, MOUSE_RELEASE, 0, &mouse_release, &data);
	mlx_hook(data.w_id, MOUSE_MOVE, 0, &mouse_move, &data);
	mlx_loop_hook(data.tun_id, &draw_to_img, &data);
	mlx_loop(data.tun_id);
}
