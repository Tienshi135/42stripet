/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:48:26 by stripet           #+#    #+#             */
/*   Updated: 2025/08/01 18:10:42 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    FragTrap dude1("F1");
    ScavTrap dude2("S1");

    dude1.takeDamage(5);
    dude1.highFivesGuys();
    dude2.guardGate();
    dude2.attack("F1");
    dude1.attack("S1");
    return (0);
}