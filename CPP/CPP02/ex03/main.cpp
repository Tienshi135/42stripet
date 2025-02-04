/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:49:56 by tienshi           #+#    #+#             */
/*   Updated: 2025/01/22 18:41:49 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main()
{
	std::string ret;
	Point a(0.0f, 7.45f);
	Point b(9.1f, 3.1f);
	Point c(5.0f, 0.0f);
	Point point(5.0f, 5.0f);
	ret = bsp(a, b, c, point) ? "true" : "false";
	std::cout << "The point being in the triangle is " << ret << "!" << std::endl;
	
	return (0);
}