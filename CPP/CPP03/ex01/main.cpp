/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:36:54 by stripet           #+#    #+#             */
/*   Updated: 2025/02/04 15:07:57 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap dude1("Scavtrap1");
    ScavTrap dude2("Scavtrap2");

    dude1.guardGate();
    dude2.guardGate();
    dude2.guardGate();
    dude2.attack("Scavtrap1");
    dude1.takeDamage(100);
    dude1.guardGate();
    return (0);
}
    