/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:50:06 by tienshi           #+#    #+#             */
/*   Updated: 2025/06/02 15:14:05 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

typedef void (Harl::*FnctPtr)();

int getLevelIndex(const std::string& level)
{
    if (level == "DEBUG" || level == "debug") return 1;
    if (level == "INFO" || level == "info") return 2;
    if (level == "WARNING" || level == "warning") return 3;
    if (level == "ERROR" || level == "error") return 4;
    return -1;
}

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
	FnctPtr functions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int index = getLevelIndex(level);
	if (index == -1)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return;
	}
	for (int i = 0; i < index; i++)
		(this->*functions[i])();
}