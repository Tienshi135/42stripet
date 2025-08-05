/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:38:51 by stripet           #+#    #+#             */
/*   Updated: 2025/08/01 18:38:05 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name) : _Name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
    std::cout << "ClapTrap " << _Name << " is created." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _Name << " is destroyed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    *this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    this->_Name = copy._Name;
    this->_HitPoints = copy._HitPoints;
    this->_EnergyPoints = copy._EnergyPoints;
    this->_AttackDamage = copy._AttackDamage;
    return *this;
}

void ClapTrap::attack(const std::string &target)
{
    if (!this->_HitPoints)
    {
        std::cout << "ClapTrap " << _Name << " is already dead and can't attack." << std::endl;
        return ;
    }
    if (!this->_EnergyPoints)
    {
        std::cout << "ClapTrap " << _Name << " is out of energy and can't attack." << std::endl;
        return ;
    }
    this->_EnergyPoints--;
    std::cout << "ClapTrap " << _Name << " attacks " << target << ", causing " << _AttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (!this->_HitPoints)
    {
        std::cout << "ClapTrap " << _Name << " is already dead and can't die further than death." << std::endl;
        return ;
    }
    if (amount > this->_HitPoints)
        amount = this->_HitPoints;
    std::cout << "ClapTrap " << _Name << " takes " << amount << " points of damage!" << std::endl;
    this->_HitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!this->_HitPoints)
    {
        std::cout << "ClapTrap " << _Name << " is already dead and can't be repaired." << std::endl;
        return ;
    }
    if (!this->_EnergyPoints)
    {
        std::cout << "ClapTrap " << _Name << " is out of energy and can't be repaired." << std::endl;
        return ;
    }
    this->_EnergyPoints--;
    std::cout << "ClapTrap " << _Name << " is repaired for " << amount << " points!" << std::endl;
    this->_HitPoints += amount;
}
