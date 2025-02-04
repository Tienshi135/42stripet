/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:15:39 by tienshi           #+#    #+#             */
/*   Updated: 2024/12/12 17:32:10 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char**argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./sed [input_file] [str1] [str2]" << std::endl;
		return 1;
	}
	std::ifstream input(argv[1]);
	if (!input.is_open())
	{
		std::cout << "Error: Could not open file :" << argv[1] << std::endl;
		return -42;
	}
	std::ofstream output(std::string(argv[1]) + ".replace");
	if (!output.is_open())
	{
		std::cout << "Error: Could not create file :" << std::string(argv[1]) + ".replace" << std::endl;
		return -42;
	}
	std::string line;
	while (std::getline(input, line))
	{
		size_t pos = 0;
		while ((pos = line.find(argv[2], pos)) != std::string::npos)
		{
			line = line.substr(0, pos) + argv[3] + line.substr(pos + strlen(argv[2]));
			pos += strlen(argv[3]);
		}
		output << line << std::endl;
	}
}