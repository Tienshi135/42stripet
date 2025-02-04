/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:08:56 by tienshi           #+#    #+#             */
/*   Updated: 2024/12/19 15:20:48 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char**argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: ./Harl [level]" << std::endl;
		return 1;
	}
	int level = getLevelIndex(argv[1]);
	Harl Harl;
	switch (level)
	{
		case 1:
			Harl.complain("DEBUG");
			break;
		case 2:
			Harl.complain("DEBUG");
			Harl.complain("INFO");
			
			break;
		case 3:
			Harl.complain("DEBUG");
			Harl.complain("INFO");
			Harl.complain("WARNING");
			break;
		case 4:
			Harl.complain("DEBUG");
			Harl.complain("INFO");
			Harl.complain("WARNING");
			Harl.complain("ERROR");
			break;
		default:
			Harl.complain("irrelevant");
			break;
	}
}