/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:37:40 by stripet           #+#    #+#             */
/*   Updated: 2025/02/04 16:51:31 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap " << name << " is created." << std::endl;
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->getName() << " is destroyed." << std::endl;
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
    if (!this->getHitPoints())
    {
        std::cout << "FragTrap " << this->getName() << " is already dead and can't give high fives." << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->getName() << " gives enthusiastic high fives." << std::endl;
}