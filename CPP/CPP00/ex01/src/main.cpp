/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:54:50 by tienshi           #+#    #+#             */
/*   Updated: 2024/12/01 17:57:49 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"
#include "PhoneBook.hpp"

int main()
{
	std::string command;

	std::cout << YELLOW << "Initialiazing PhoneBook..." << NC << std::endl;
	sleep(2);
	PhoneBook pb;
	std::cout << GREEN << "PhoneBook initialized" << NC << std::endl;
	sleep(2);
	std::system("clear");
	std::cout << BLUE << "Welcome to your PhoneBook !" << NC << std::endl << std::endl;
	std::cout << "Available commands are " << PASTEL_BLUE << "ADD" << NC << " , " << PINK << "SEARCH" << NC << " and " << PURPLE << "EXIT" << NC << std::endl;
	std::cout << "Please enter a command: ";
	std::getline(std::cin, command);
	while (command != "EXIT" && command != "exit")
	{
		bool trigger = false;

		if (command == "ADD" || command == "add")
		{
			pb.AddContact();
			trigger = true;
		}
		else if (command == "SEARCH" || command == "search")
		{
			pb.SearchContact();
			trigger = true;
		}
		else
		{
			std::cout << RED << "Invalid command" << NC << std::endl;
		}
		if (trigger)
		{
			std::cout << BLUE << "Welcome to your PhoneBook !" << NC << std::endl << std::endl;
			std::cout << "Available commands are " << PASTEL_BLUE << "ADD" << NC << " , " << PINK << "SEARCH" << NC << " and " << PURPLE << "EXIT" << NC << std::endl;
		}
		std::cout << "Please enter a command: ";
		std::getline(std::cin, command);
	}
	return 0;
}