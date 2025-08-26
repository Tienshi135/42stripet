/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:37:40 by stripet           #+#    #+#             */
/*   Updated: 2025/08/02 15:55:47 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->_HitPoints = 100;
    this->_AttackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
    this->_HitPoints = 100;
    this->_EnergyPoints = 100;
    this->_AttackDamage = 30;
    std::cout << "FragTrap " << name << " is created." << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->_Name << " is destroyed." << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    *this = copy;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    ClapTrap::operator=(copy);
    return *this;
}

void FragTrap::highFivesGuys()
{
    if (!this->_HitPoints)
    {
        std::cout << "FragTrap " << this->_Name << " is already dead and can't give high fives." << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->_Name << " gives enthusiastic high fives." << std::endl;
}