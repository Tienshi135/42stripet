/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:12:27 by stripet           #+#    #+#             */
/*   Updated: 2025/02/10 14:12:52 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap diamondTrap("DiamondTrap");
    diamondTrap.attack("target");
    diamondTrap.takeDamage(10);
    diamondTrap.beRepaired(10);
    diamondTrap.guardGate();
    diamondTrap.highFivesGuys();
    diamondTrap.whoAmI();
    return 0;
}