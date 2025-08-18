/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:35:36 by stripet           #+#    #+#             */
/*   Updated: 2025/08/18 14:45:05 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    Form f1("Tax", 50, 30);
    std::cout << f1;
    
    // Test invalid Form construction (sign grade too high)   
    try {
        Form f2("InvalidSignHigh", 0, 30);
    } catch (const std::exception &e) {
        std::cout << "Exception for sign grade 0: " << e.what() << std::endl;
    }

    // Test invalid Form construction (execute grade too high)
    try {
        Form f3("InvalidExecHigh", 50, 0);
    } catch (const std::exception &e) {
        std::cout << "Exception for execute grade 0: " << e.what() << std::endl;
    }

    // Test invalid Form construction (sign grade too low)
    try {
        Form f4("InvalidSignLow", 151, 30);
    } catch (const std::exception &e) {
        std::cout << "Exception for sign grade 151: " << e.what() << std::endl;
    }

    // Test invalid Form construction (execute grade too low)
    try {
        Form f5("InvalidExecLow", 50, 151);
    } catch (const std::exception &e) {
        std::cout << "Exception for execute grade 151: " << e.what() << std::endl;
    }

    // Test signing with sufficient grade
    try {
        Bureaucrat b1("Alice", 40);
        Form f6("Contract", 50, 30);
        std::cout << b1 << std::endl;
        b1.signForm(f6);
        std::cout << f6;
    } catch (const std::exception &e) {
        std::cout << "Exception during signing with sufficient grade: " << e.what() << std::endl;
    }

    // Test signing with insufficient grade
    try {
        Bureaucrat b2("Bob", 100);
        Form f7("Agreement", 50, 30);
        std::cout << b2 << std::endl;
        b2.signForm(f7);
        std::cout << f7;
    } catch (const std::exception &e) {
        std::cout << "Exception during signing with insufficient grade: " << e.what() << std::endl;
    }

    return 0;
}