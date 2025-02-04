/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:50:06 by tienshi           #+#    #+#             */
/*   Updated: 2024/12/17 22:19:29 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

typedef void (Harl::*FnctPtr)();

Harl::Harl(void)
{
	std::cout << "Harl constructor called" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Harl destructor called" << std::endl;
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	FnctPtr values[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string keys[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (size_t i = 0; i < 4; i++)
	{
		if (keys[i] == level)
		{
			(this->*values[i])();
			return;
		}
	}
	std::cout << "Harl can't complain at this level yet..." << std::endl;
}