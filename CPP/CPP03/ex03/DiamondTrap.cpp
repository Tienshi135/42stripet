/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:04:51 by stripet           #+#    #+#             */
/*   Updated: 2025/06/02 15:25:02 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    this->_Name = name;
    std::cout << "DiamondTrap " << this->_Name << " is created." << std::endl;
    this->setHitPoints(FragTrap::getHitPoints());
    this->setEnergyPoints(ScavTrap::getEnergyPoints());
    this->setAttackDamage(FragTrap::getAttackDamage());
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
    ScavTrap::operator=(copy);
    FragTrap::operator=(copy);
    this->_Name = copy._Name;
    return *this;
}

void::DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap " << this->_Name << " is " << this->getName() << "." << std::endl;
}

