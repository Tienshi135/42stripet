/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:55:37 by tienshi           #+#    #+#             */
/*   Updated: 2025/04/15 16:44:35 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook constructor called" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::system("clear");
	std::cout << "PhoneBook destructor called" << std::endl;
}

static bool valid_number(const std::string& number)
{
    size_t start = 0;
    int digit_count = 0;
    if (number[0] == '+')
        start = 1;
    for (size_t i = start; i < number.length(); i++)
    {
        if (std::isdigit(number[i]))
            digit_count++;
        else if (number[i] != ' ')
            return false;
    }
    return digit_count >= 10;
}

static void reversePop(Contacts *PB)
{
	int i;

	for (i = 0; i < 7; i++)
	{
		PB[i] = PB[i + 1];
	}
}
void PhoneBook::AddContact(void)
{
	std::string input;
	int 		head;

	for (head = 0; PB[head].isInit(); head++)
	{
		if (head == 7)
		{
			reversePop(PB);
			break;
		}
	}
	std::system("clear");
	std::cout << "Adding a new contact" << std::endl << std::endl;
	std::cout << RED << "Warning !\nFailure to provide accurate informations will result in consequences." << NC << std::endl << std::endl;
	std::cout << PASTEL_BLUE << "Please enter the first name: " << std::endl << DARK_GREEN;
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << RED << "First Name can't be empty" << std::endl << std::endl;
		std::cout << PASTEL_BLUE << "Please enter the first name: " << std::endl << DARK_GREEN;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::system("clear");
			return;
		}
	}
	PB[head].setFirstName(input);
	std::cout << PASTEL_BLUE << "Please enter the last name: " << std::endl << DARK_GREEN;
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << RED << "Last Name can't be empty" << std::endl << std::endl;
		std::cout << PASTEL_BLUE << "Please enter the Last name: " << std::endl << DARK_GREEN;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::system("clear");
			return;
		}
	}
	PB[head].setLastName(input);
	std::cout << PASTEL_BLUE << "Please enter the nickname: " << std::endl << DARK_GREEN;
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << RED << "Nickname can't be empty" << std::endl << std::endl;
		std::cout << PASTEL_BLUE << "Please enter the Nickname: " << std::endl << DARK_GREEN;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::system("clear");
			return;
		}
	}
	PB[head].setNickname(input);
	std::cout << PASTEL_BLUE << "Please enter the phone number: " << std::endl << DARK_GREEN;
	std::getline(std::cin, input);
	while (!valid_number(input))
	{
		std::cout << RED << "Phone number is invalid. Carefull" << PASTEL_BLUE << std::endl;
		std::cout << "Please enter the phone number: " << DARK_GREEN << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::system("clear");
			return;
		}
	}
	PB[head].setPhoneNumber(input);
	std::cout << PASTEL_BLUE << "Please enter their darkest secret ^-^" << std::endl << DARK_GREEN;
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << RED << "You can't hide your darkest secrets..." << std::endl << std::endl;
		std::cout << PASTEL_BLUE << "Please enter their darkest secret: " << std::endl << DARK_GREEN;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::system("clear");
			return;
		}
	}
	PB[head].setDarkestSecret(input);
	std::cout << std::endl << YELLOW << "Loading..." << NC << std::endl;
	sleep(1);
	std::cout << GREEN << "Contact added !" << NC << std::endl;
	sleep(2);
	std::system("clear");
}

void	PhoneBook::SearchContact(void) const
{
	std::string buffer;
	size_t		l;

	std::system("clear");
	std::cout << "               Your Phonebook!               " << std::endl;
	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|    ID    |    FN    |    LN    |    NN    |" << std::endl;
	for (size_t i = 0; i < 8 && this->PB[i].isInit(); i++)
	{
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "|" << i + 1 << "         |";
		buffer = this->PB[i].getFirstName();
		for (l = 0; buffer[l] && l < 10; l++)
		{
			if (l == 9 && buffer[10])
				std::cout << ".";
			else
				std::cout << buffer[l];
		}
		while (l++ < 10)
			std::cout << " ";
		std::cout << "|";
		buffer = this->PB[i].getLastName();
		for (l = 0; buffer[l] && l < 10; l++)
		{
			if (l == 9 && buffer[10])
				std::cout << ".";
			else
				std::cout << buffer[l];
		}
		while (l++ < 10)
			std::cout << " ";
		std::cout << "|";
		buffer = this->PB[i].getNickname();
		for (l = 0; buffer[l] && l < 10; l++)
		{
			if (l == 9 && buffer[10])
				std::cout << ".";
			else
				std::cout << buffer[l];
		}
		while (l++ < 10)
			std::cout << " ";
		std::cout << "|" << std::endl;
	}
	std::cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl << std::endl;
	if (!this->PB[0].isInit())
	{
		std::cout << "PhoneBook empty. Please add Contacts before searching" << std::endl;
		sleep(6);
		std::system("clear");
		return ;
	}
	int		nbr;
	while (true)
    {
        std::cout << "Enter ID of Contact you want to search \n(type \"return\" to go back to main menu)" << std::endl;
        std::getline(std::cin, buffer);
        if (buffer == "return" || std::cin.eof())
        {
            std::system("clear");
            return;
        }
        try
		{
            std::stringstream strm(buffer);
			strm >> nbr;
            if (nbr >= 1 && nbr <= 8 && this->PB[nbr - 1].isInit())
            {
                break;
            }
            else
            {
                std::cout << std::endl << "Invalid ID. Please enter a number between 1 and 8 for an initialized contact." << std::endl << std::endl;
            }
        } catch (const std::invalid_argument& e) {
            std::cout << std::endl << "Invalid input. Please enter a number between 1 and 8." << std::endl << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << std::endl << "Number out of range. Please enter a number between 1 and 8." << std::endl << std::endl;
        }
    }
	std::system("clear");
	nbr -= 1;
	std::cout << "First name : " << this->PB[nbr].getFirstName() << std::endl;
	std::cout << "Last name : " << this->PB[nbr].getLastName() << std::endl;
	std::cout << "Nickname : " << this->PB[nbr].getNickname() << std::endl;
	std::cout << "Phone Number : " << this->PB[nbr].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << this->PB[nbr].getDarkestSecret() << std::endl << std::endl;
	std::cout << "Type return to go back to main menu." << std::endl;
	std::getline(std::cin, buffer);
	while (buffer != "return" && !std::cin.eof())
		std::getline(std::cin, buffer);
	std::system("clear");
}