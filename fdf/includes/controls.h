/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:40:04 by tienshi           #+#    #+#             */
/*   Updated: 2024/02/22 08:27:25 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

enum e_actions{
	ON_DESTROY = 17,
	KEY_PRESS = 02,
	MOUSE_PRESS = 04,
	MOUSE_RELEASE = 05,
	MOUSE_MOVE = 06
};

enum e_keys{
	ESC = 53,
	ARROW_UP = 126,
	ARROW_DOWN = 125,
	ARROW_LEFT = 123,
	ARROW_RIGHT = 124,
	LEFT_CLICK = 01,
	RIGHT_CLICK = 02,
	SCROLL_UP = 04,
	SCROLL_DOWN = 05,
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	R = 15,
	I = 34,
	C = 8
};

int	close_window(t_data *data);
int	key_press(int key, t_data *data);
int	mouse_press(int button, int x, int y, t_data *data);
int	mouse_release(int button, int x, int y, t_data *data);
int	mouse_move(int x, int y, t_data *data);

#endif