/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:15:39 by tienshi           #+#    #+#             */
/*   Updated: 2025/06/02 12:00:04 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>

int	main(int argc, char**argv)
{
	std::ofstream output;
	std::ifstream input;

	if (argc != 4)
	{
		std::cout << "Usage: ./sed [input_file] [str1] [str2]" << std::endl;
		return 1;
	}
	input.open(argv[1]);
	if (!input.is_open())
	{
		std::cout << "Error: Could not open file :" << argv[1] << std::endl;
		return -42;
	}
	output.open((std::string(argv[1]) + ".replace").c_str());
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