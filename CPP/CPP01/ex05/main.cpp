/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:02:46 by tienshi           #+#    #+#             */
/*   Updated: 2025/06/02 15:17:43 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	std::string input;
	Harl Harl;

	while (!std::cin.eof())
	{
		std::cout << "I present you Harl. He accepts four different inputs, DEBUG, INFO, WARNING, ERROR. Type exit to leave." << std::endl << "Please input one :" << std::endl;
		std::cin >> input;
		if ((input == "exit" || input == "EXIT") || std::cin.eof())
			break;
		Harl.complain(input);
	}
}