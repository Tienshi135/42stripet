/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:35:36 by stripet           #+#    #+#             */
/*   Updated: 2025/08/18 13:09:09 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    // Test valid construction
    Bureaucrat  b1("John", 10);
    Bureaucrat  b2("Steve", 150);
    Bureaucrat  b3("The boss", 1);

    // Test out-of-bounds construction
    try {
        Bureaucrat b4("TooHigh", 0);
    } catch (const std::exception &e) {
        std::cout << "Exception caught for grade 0: " << e.what();
    }
    try {
        Bureaucrat b5("TooLow", 151);
    } catch (const std::exception &e) {
        std::cout << "Exception caught for grade 151: " << e.what();
    }

    // Test Promote protection
    try {
        b3.Promote();
    } catch (const std::exception &e) {
        std::cout << "Exception caught on promote at grade 1: " << e.what();
    }

    // Test Demote protection
    try {
        b2.Demote();
    } catch (const std::exception &e) {
        std::cout << "Exception caught on demote at grade 150: " << e.what();
    }

    // Show Promote and Demote work correctly
    std::cout << "Before promote: " << b1 << std::endl;
    b1.Promote();
    std::cout << "After promote: " << b1 << std::endl;

    std::cout << "Before demote: " << b1 << std::endl;
    b1.Demote();
    std::cout << "After demote: " << b1 << std::endl;

    return 0;
}