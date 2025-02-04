/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:02:46 by tienshi           #+#    #+#             */
/*   Updated: 2024/12/17 22:20:39 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	std::string input;
	Harl Harl;

	while (true)
	{
		std::cout << "I present you Harl. He accepts four different inputs, DEBUG, INFO, WARNING, ERROR. Type exit to leave." << std::endl << "Please input one :" << std::endl;
		std::cin >> input;
		if (input == "exit" || input == "EXIT")
			break;
		Harl.complain(input);
	}
}