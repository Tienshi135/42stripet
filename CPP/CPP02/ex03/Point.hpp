/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:42:40 by tienshi           #+#    #+#             */
/*   Updated: 2025/01/22 18:33:54 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
private:
	Fixed _x;
	Fixed _y;
public:
	Point(const float x, const float y);
	~Point();
	Fixed x() const;
	Fixed y() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);