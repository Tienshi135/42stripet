/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:13:25 by tienshi           #+#    #+#             */
/*   Updated: 2025/01/22 15:48:41 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _value;
	static const int _fractionalBits = 8;
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &fixed);
	~Fixed();
	Fixed &operator=(const Fixed &fixed);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	static Fixed& min(Fixed &fixed1, Fixed &fixed2);
	static const Fixed& min(Fixed const &fixed1, Fixed const &fixed2);
	static Fixed& max(Fixed &fixed1, Fixed &fixed2);
	static const Fixed& max(Fixed const &fixed1, Fixed const &fixed2);
	friend std::ostream& operator<<(std::ostream &out, const Fixed &fixed);
	friend bool operator<(const Fixed &fixed1, const Fixed &fixed2);
	friend bool operator>(const Fixed &fixed1, const Fixed &fixed2);
	friend bool operator<=(const Fixed &fixed1, const Fixed &fixed2);
	friend bool operator>=(const Fixed &fixed1, const Fixed &fixed2);
	friend bool operator==(const Fixed &fixed1, const Fixed &fixed2);
	friend bool operator!=(const Fixed &fixed1, const Fixed &fixed2);
	friend Fixed operator+(const Fixed &fixed1, const Fixed &fixed2);
	friend Fixed operator-(const Fixed &fixed1, const Fixed &fixed2);
	friend Fixed operator*(const Fixed &fixed1, const Fixed &fixed2);
	friend Fixed operator/(const Fixed &fixed1, const Fixed &fixed2);
	Fixed &operator++();
	Fixed operator++(int);
};