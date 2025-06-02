/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:39:04 by stripet           #+#    #+#             */
/*   Updated: 2025/06/02 15:32:18 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap
{
    private:
        std::string _Name;
        unsigned int _HitPoints;
        unsigned int _EnergyPoints;
        unsigned int _AttackDamage;
    public:
        ClapTrap(const std::string name);
        ~ClapTrap();
        ClapTrap(const ClapTrap &copy);
        ClapTrap &operator=(const ClapTrap &copy);
        virtual void attack(const std::string &target) = 0;
        virtual void takeDamage(unsigned int amount) = 0;
        virtual void beRepaired(unsigned int amount) = 0;
        std::string getName() const;
        unsigned int getHitPoints() const;
        unsigned int getEnergyPoints() const;
        unsigned int getAttackDamage() const;
        void setHitPoints(unsigned int hitPoints);
        void setEnergyPoints(unsigned int energyPoints);
};