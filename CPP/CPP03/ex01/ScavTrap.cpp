/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:09:13 by stripet           #+#    #+#             */
/*   Updated: 2025/06/02 15:30:00 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
    this->_IsFree = true;
    std::cout << "ScavTrap " << name << " is created." << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->getName() << " is destroyed." << std::endl;
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
    if (!this->getHitPoints())
    {
        std::cout << "ScavTrap " << this->getName() << " is already dead and can't guard the gate." << std::endl;
        return ;
    }
    if (!this->getEnergyPoints())
    {
        std::cout << "ScavTrap " << this->getName() << " is out of energy and can't guard the gate." << std::endl;
        return ;
    }
    if (!this->_IsFree)
    {
        std::cout << "ScavTrap " << this->getName() << " is already guarding the gate." << std::endl;
        return ;
    }
    this->_IsFree = false;
    this->setEnergyPoints(this->getEnergyPoints() - 1);
    std::cout << "ScavTrap " << this->getName() << " have enterred in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (!this->_IsFree)
    {
        std::cout << "ScavTrap " << this->getName() << " is guarding the gate and can't attack." << std::endl;
        return ;
    }
    if (!this->getHitPoints())
    {
        std::cout << "ClapTrap " << this->getName() << " is already dead and can't attack." << std::endl;
        return ;
    }
    if (!this->getEnergyPoints())
    {
        std::cout << "ClapTrap " << this->getName() << " is out of energy and can't attack." << std::endl;
        return ;
    }
    this->setEnergyPoints(this->getEnergyPoints() - 1);
    std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}