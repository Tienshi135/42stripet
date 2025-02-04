/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:45:59 by tienshi           #+#    #+#             */
/*   Updated: 2025/02/04 12:47:57 by stripet          ###   ########.fr       */
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

Point::Point(const Point &point) : _x(point._x), _y(point._y)
{
	std::cout << "Point copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &point)
{
	std::cout << "Point assignation operator called" << std::endl;
	this->_x = point._x;
	this->_y = point._y;
	return *this;
}

Fixed Point::x() const
{
	return this->_x;
}

Fixed Point::y() const
{
	return this->_y;
}