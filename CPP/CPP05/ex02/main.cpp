/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:35:36 by stripet           #+#    #+#             */
/*   Updated: 2025/08/18 14:58:30 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void)
{
    AForm f1("Tax", 50, 30);
    std::cout << f1;
    
    // Test invalid AForm construction (sign grade too high)   
    try {
        AForm f2("InvalidSignHigh", 0, 30);
    } catch (const std::exception &e) {
        std::cout << "Exception for sign grade 0: " << e.what() << std::endl;
    }

    // Test invalid AForm construction (execute grade too high)
    try {
        AForm f3("InvalidExecHigh", 50, 0);
    } catch (const std::exception &e) {
        std::cout << "Exception for execute grade 0: " << e.what() << std::endl;
    }

    // Test invalid AForm construction (sign grade too low)
    try {
        AForm f4("InvalidSignLow", 151, 30);
    } catch (const std::exception &e) {
        std::cout << "Exception for sign grade 151: " << e.what() << std::endl;
    }

    // Test invalid AForm construction (execute grade too low)
    try {
        AForm f5("InvalidExecLow", 50, 151);
    } catch (const std::exception &e) {
        std::cout << "Exception for execute grade 151: " << e.what() << std::endl;
    }

    // Test signing with sufficient grade
    try {
        Bureaucrat b1("Alice", 40);
        AForm f6("Contract", 50, 30);
        std::cout << b1 << std::endl;
        b1.signAForm(f6);
        std::cout << f6;
    } catch (const std::exception &e) {
        std::cout << "Exception during signing with sufficient grade: " << e.what() << std::endl;
    }

    // Test signing with insufficient grade
    try {
        Bureaucrat b2("Bob", 100);
        AForm f7("Agreement", 50, 30);
        std::cout << b2 << std::endl;
        b2.signAForm(f7);
        std::cout << f7;
    } catch (const std::exception &e) {
        std::cout << "Exception during signing with insufficient grade: " << e.what() << std::endl;
    }

    return 0;
}