/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:43:33 by tienshi           #+#    #+#             */
/*   Updated: 2025/01/22 18:11:10 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed a1 = (b.x() - a.x()) * (point.y() - a.y()) - (b.y() - a.y()) * (point.x() - a.x());
	Fixed a2 = (c.x() - b.x()) * (point.y() - b.y()) - (c.y() - b.y()) * (point.x() - b.x());
	Fixed a3 = (a.x() - c.x()) * (point.y() - c.y()) - (a.y() - c.y()) * (point.x() - c.x());
	if ((a1 >= 0 && a2 >= 0 && a3 >= 0) || (a1 <= 0 && a2 <= 0 && a3 <= 0))
		return true;
	return false;
}