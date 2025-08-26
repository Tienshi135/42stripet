/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:04:51 by stripet           #+#    #+#             */
/*   Updated: 2025/08/02 15:56:44 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name")
{
    this->_Name = name;   
    std::cout << "DiamondTrap " << this->_Name << " is created." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _Name << " is destroyed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
    *this = copy;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
    ClapTrap::operator=(copy);
    this->_Name = copy._Name;
    return *this;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() const
{
    std::cout << "DiamondTrap " << this->_Name << " is " << ClapTrap::_Name << "." << std::endl;
}

void DiamondTrap::announcestats() const
{
    std::cout << "DiamondTrap " << this->_Name << "has " << this->_HitPoints << " hit points, " << this->_EnergyPoints << "energy points, " << "and " << this->_AttackDamage << " attack damage." << std::endl;
}