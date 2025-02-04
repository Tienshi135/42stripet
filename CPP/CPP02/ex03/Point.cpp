/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:45:59 by tienshi           #+#    #+#             */
/*   Updated: 2025/01/22 18:06:13 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	std::cout << "Point constructor called" << std::endl;
}

Point::~Point()
{
	std::cout << "Point destructor called" << std::endl;
}

Fixed Point::x() const
{
	return this->_x;
}

Fixed Point::y() const
{
	return this->_y;
}