/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:35:36 by stripet           #+#    #+#             */
/*   Updated: 2025/09/03 12:36:50 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void)
{
    try {
        Intern intern;
        Bureaucrat boss("Boss", 1);
        Bureaucrat worker("Worker", 50);

        // Test form creation
        AForm* form1 = intern.makeForm("presidential pardon request", "Alice");
        AForm* form2 = intern.makeForm("robotomy request", "Bob");
        AForm* form3 = intern.makeForm("shrubbery request", "home");

        // Test signing
        boss.signAForm(*form1);
        worker.signAForm(*form2);
        boss.signAForm(*form3);

        // Test execution
        boss.executeAForm(*form1);
        worker.executeAForm(*form2);
        boss.executeAForm(*form3);

        // Test unknown form
        AForm* form4 = intern.makeForm("unknown form", "Nobody");
        if (!form4) std::cout << "Unknown form creation handled.\n";

        // Clean up
        delete form1;
        delete form2;
        delete form3;
        delete form4;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}