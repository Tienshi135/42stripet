/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 12:35:36 by stripet           #+#    #+#             */
/*   Updated: 2025/08/29 00:48:54 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void testShrubberyCreationForm()
{
    std::cout << "\n=== Testing ShrubberyCreationForm ===" << std::endl;
    
    try {
        ShrubberyCreationForm form("home");
        Bureaucrat gardener("Gardener", 137);  // Grade needed to sign: 145, execute: 137
        Bureaucrat intern("Intern", 146);
        
        std::cout << "Form: " << form << std::endl;
        std::cout << "Gardener: " << gardener << std::endl;
        std::cout << "Intern: " << intern << std::endl;
        
        // Try signing with insufficient grade
        try {
            intern.signAForm(form);
        }
        catch (std::exception& e) {
            std::cout << "✓ Intern couldn't sign: " << e.what() << std::endl;
        }
        
        // Sign with sufficient grade
        gardener.signAForm(form);
        std::cout << "✓ Form signed by gardener" << std::endl;
        std::cout << "Form after signing: " << form << std::endl;
        
        // Execute the form
        gardener.executeAForm(form);
        std::cout << "✓ Form executed by gardener" << std::endl;
        
    }
    catch (std::exception& e) {
        std::cout << "✗ Unexpected exception: " << e.what() << std::endl;
    }
}

void testRobotomyRequestForm()
{
    std::cout << "\n=== Testing RobotomyRequestForm ===" << std::endl;
    
    try {
        RobotomyRequestForm form("Bender");
        Bureaucrat engineer("Engineer", 45);  // Grade needed to sign: 72, execute: 45
        Bureaucrat technician("Technician", 73);
        
        std::cout << "Form: " << form << std::endl;
        std::cout << "Engineer: " << engineer << std::endl;
        std::cout << "Technician: " << technician << std::endl;
        
        // Try signing with insufficient grade
        try {
            technician.signAForm(form);
        }
        catch (std::exception& e) {
            std::cout << "✓ Technician couldn't sign: " << e.what() << std::endl;
        }
        
        // Sign and execute with sufficient grade
        engineer.signAForm(form);
        std::cout << "✓ Form signed by engineer" << std::endl;
        
        engineer.executeAForm(form);
        std::cout << "✓ Form executed by engineer" << std::endl;
        
        // Try multiple executions to see randomness
        std::cout << "Trying multiple executions:" << std::endl;
        for (int i = 0; i < 5; i++) {
            engineer.executeAForm(form);
        }
        
    }
    catch (std::exception& e) {
        std::cout << "✗ Unexpected exception: " << e.what() << std::endl;
    }
}

void testPresidentialPardonForm()
{
    std::cout << "\n=== Testing PresidentialPardonForm ===" << std::endl;
    
    try {
        PresidentialPardonForm form("Criminal");
        Bureaucrat president("President", 5);   // Grade needed to sign: 25, execute: 5
        Bureaucrat assistant("Assistant", 26);
        
        std::cout << "Form: " << form << std::endl;
        std::cout << "President: " << president << std::endl;
        std::cout << "Assistant: " << assistant << std::endl;
        
        // Try signing with insufficient grade
        try {
            assistant.signAForm(form);
        }
        catch (std::exception& e) {
            std::cout << "✓ Assistant couldn't sign: " << e.what() << std::endl;
        }
        
        // Sign and execute with sufficient grade
        president.signAForm(form);
        std::cout << "✓ Form signed by president" << std::endl;
        
        president.executeAForm(form);
        std::cout << "✓ Form executed by president" << std::endl;
        
    }
    catch (std::exception& e) {
        std::cout << "✗ Unexpected exception: " << e.what() << std::endl;
    }
}

void testFormExecutionWithoutSigning()
{
    std::cout << "\n=== Testing Form Execution Without Signing ===" << std::endl;
    
    ShrubberyCreationForm form("test");
    Bureaucrat highLevel("HighLevel", 1);
    
    std::cout << "Trying to execute unsigned form..." << std::endl;
    highLevel.executeAForm(form);
}

void testInsufficientGradeExecution()
{
    std::cout << "\n=== Testing Insufficient Grade for Execution ===" << std::endl;
    
    ShrubberyCreationForm form("test");
    Bureaucrat signer("Signer", 140);    // Can sign (145) but can't execute (137)
    Bureaucrat lowLevel("LowLevel", 140);
    
    // Sign the form
    signer.signAForm(form);
    std::cout << "✓ Form signed" << std::endl;
    
    // Try to execute with insufficient grade
    std::cout << "Trying to execute with insufficient grade..." << std::endl;
    lowLevel.executeAForm(form);
}

int main(void)
{
    std::cout << "========== BUREAUCRAT AND FORM TESTS ==========" << std::endl;
    
    testShrubberyCreationForm();
    testRobotomyRequestForm();
    testPresidentialPardonForm();
    testFormExecutionWithoutSigning();
    testInsufficientGradeExecution();
    
    std::cout << "\n========== ALL TESTS COMPLETED ==========" << std::endl;
    
    return 0;
}