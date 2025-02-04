/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:38:28 by stripet           #+#    #+#             */
/*   Updated: 2025/02/04 13:06:52 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap dude1("Claptrap1");
    ClapTrap dude2("Claptrap2");

    dude1.attack("Claptrap2");
    dude2.takeDamage(5);
    dude2.beRepaired(3);
    dude2.attack("Claptrap1");
    dude1.takeDamage(10);
    dude2.attack("Claptrap1");
    dude1.takeDamage(5);
    dude1.attack("Claptrap2");
    dude1.beRepaired(10);
    dude2.beRepaired(1);
    dude2.beRepaired(1);
    dude2.beRepaired(1);
    dude2.beRepaired(1);
    dude2.beRepaired(1);
    dude2.beRepaired(1);
    dude2.beRepaired(1);
    dude2.beRepaired(1);
    dude2.attack("Claptrap1");
    return 0;
}