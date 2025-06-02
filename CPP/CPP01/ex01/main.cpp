/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:57:38 by tienshi           #+#    #+#             */
/*   Updated: 2025/06/02 15:13:03 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/Zombie.hpp"

int main()
{
	Zombie* horde = zombieHorde(5, "HordeZombie");
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}