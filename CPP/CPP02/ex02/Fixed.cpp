/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:13:20 by tienshi           #+#    #+#             */
/*   Updated: 2025/01/22 15:49:04 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

bool operator<(const Fixed &fixed1, const Fixed &fixed2)
{
    return fixed1.getRawBits() < fixed2.getRawBits();
}

bool operator>(const Fixed &fixed1, const Fixed &fixed2)
{
    return fixed1.getRawBits() > fixed2.getRawBits();
}

bool operator<=(const Fixed &fixed1, const Fixed &fixed2)
{
    return fixed1.getRawBits() <= fixed2.getRawBits();
}

bool operator>=(const Fixed &fixed1, const Fixed &fixed2)
{
    return fixed1.getRawBits() >= fixed2.getRawBits();
}

bool operator==(const Fixed &fixed1, const Fixed &fixed2)
{
    return fixed1.getRawBits() == fixed2.getRawBits();
}

bool operator!=(const Fixed &fixed1, const Fixed &fixed2)
{
    return fixed1.getRawBits() != fixed2.getRawBits();
}

Fixed operator+(const Fixed &fixed1, const Fixed &fixed2)
{
    Fixed ret;
    ret.setRawBits(fixed1.getRawBits() + fixed2.getRawBits());
    return ret;
}

Fixed operator-(const Fixed &fixed1, const Fixed &fixed2)
{
    Fixed ret;
    ret.setRawBits(fixed1.getRawBits() - fixed2.getRawBits());
    return ret;
}

Fixed operator*(const Fixed &fixed1, const Fixed &fixed2)
{
    Fixed ret;
    ret.setRawBits((fixed1.getRawBits() * fixed2.getRawBits()) >> Fixed::_fractionalBits);
    return ret;
}

Fixed operator/(const Fixed &fixed1, const Fixed &fixed2)
{
    Fixed ret;
    ret.setRawBits((fixed1.getRawBits() << Fixed::_fractionalBits) / fixed2.getRawBits());
    return ret;
}

Fixed &Fixed::operator++()
{
	++this->_value;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed buffer;

	buffer = *this;
	++this->_value;
	return (buffer);
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = value * (1 << this->_fractionalBits);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = (int)roundf(value * (1 << this->_fractionalBits));
}

float Fixed::toFloat(void) const
{
	return (float)this->_value / (1 << this->_fractionalBits);
}

int Fixed::toInt(void) const
{
	return this->_value / (1 << this->_fractionalBits);
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_value = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1 < fixed2) ? fixed1 : fixed2;
}

const Fixed &Fixed::min(Fixed const &fixed1, Fixed const &fixed2)
{
	return (fixed1 < fixed2) ? fixed1 : fixed2;
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1 > fixed2) ? fixed1 : fixed2;
}

const Fixed &Fixed::max(Fixed const &fixed1, Fixed const &fixed2)
{
	return (fixed1 > fixed2) ? fixed1 : fixed2;
}