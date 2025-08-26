/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:09:13 by stripet           #+#    #+#             */
/*   Updated: 2025/08/02 10:29:46 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
    this->_IsFree = true;
    this->_HitPoints = 100;
    this->_EnergyPoints = 50;
    this->_AttackDamage = 20;
    std::cout << "ScavTrap " << name << " is created." << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->_Name << " is destroyed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    *this = copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
   ClapTrap::operator=(copy);
   this->_IsFree = copy._IsFree;
   return *this;
}

void ScavTrap::guardGate()
{
    if (!this->_HitPoints)
    {
        std::cout << "ScavTrap " << this->_Name << " is already dead and can't guard the gate." << std::endl;
        return ;
    }
    if (!this->_EnergyPoints)
    {
        std::cout << "ScavTrap " << this->_Name << " is out of energy and can't guard the gate." << std::endl;
        return ;
    }
    if (!this->_IsFree)
    {
        std::cout << "ScavTrap " << this->_Name << " is already guarding the gate." << std::endl;
        return ;
    }
    this->_IsFree = false;
    this->_EnergyPoints -= 1;
    std::cout << "ScavTrap " << this->_Name << " have enterred in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (!this->_IsFree)
    {
        std::cout << "ScavTrap " << this->_Name << " is guarding the gate and can't attack." << std::endl;
        return ;
    }
    if (!this->_HitPoints)
    {
        std::cout << "ScavTrap " << this->_Name << " is already dead and can't attack." << std::endl;
        return ;
    }
    if (!this->_EnergyPoints)
    {
        std::cout << "ScavTrap " << this->_Name << " is out of energy and can't attack." << std::endl;
        return ;
    }
    this->_EnergyPoints -= 1;
    std::cout << "ScavTrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
}