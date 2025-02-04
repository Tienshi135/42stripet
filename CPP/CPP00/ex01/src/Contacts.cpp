/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:50:36 by tienshi           #+#    #+#             */
/*   Updated: 2024/11/30 13:10:07 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

Contacts::Contacts(void)
{
	std::cout << "Contacts constructor called" << std::endl;
	this->initialized = false;
}

Contacts::~Contacts(void)
{
	std::cout << "Contacts destructor called" << std::endl;
}

bool Contacts::isInit(void) const
{
	return (this->initialized);
}

void Contacts::setFirstName(std::string input)
{
	this->first_name = input;
	if (!this->initialized)
		this->initialized = true;
}

void Contacts::setLastName(std::string input)
{
	this->last_name = input;
	if (!this->initialized)
		this->initialized = true;
}

void Contacts::setNickname(std::string input)
{
	this->nickname = input;
	if (!this->initialized)
		this->initialized = true;
}

void Contacts::setPhoneNumber(std::string input)
{
	this->phone_number = input;
	if (!this->initialized)
		this->initialized = true;
}

void Contacts::setDarkestSecret(std::string input)
{
	this->darkest_secret = input;
	if (!this->initialized)
		this->initialized = true;
}

std::string	Contacts::getFirstName(void) const
{
	return (this->first_name);
}

std::string	Contacts::getLastName(void) const
{
	return (this->last_name);
}

std::string	Contacts::getNickname(void) const
{
	return (this->nickname);
}

std::string	Contacts::getPhoneNumber(void) const
{
	return (this->phone_number);
}

std::string	Contacts::getDarkestSecret(void) const
{
	return (this->darkest_secret);
}