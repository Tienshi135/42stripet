/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:44:49 by tienshi           #+#    #+#             */
/*   Updated: 2024/12/12 13:51:21 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* ptr = &str;
	std::string& ref = str;
	std::cout << "String adress :" << &str << std::endl;
	std::cout << "Pointer adress :" << &ptr << std::endl;
	std::cout << "Reference adress :" << &ref << std::endl;
	std::cout << "String value :" << str << std::endl;
	std::cout << "Pointer value :" << *ptr << std::endl;
	std::cout << "Reference value :" << ref << std::endl;
	return 0;
}