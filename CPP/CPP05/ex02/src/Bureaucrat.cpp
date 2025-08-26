/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:39:04 by stripet           #+#    #+#             */
/*   Updated: 2025/08/26 14:52:53 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

std::ostream    &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << " bureaucrat grade " << bureaucrat.getGrade();
    return (out);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void Bureaucrat::GradeTooHighException(void) const
{
    throw (std::logic_error("Grade is too high\n"));
}

void Bureaucrat::GradeTooLowException(void) const
{
    throw (std::logic_error("Grade is too low\n"));
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

unsigned int    Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void    Bureaucrat::Promote(void)
{
    if (this->_grade <= 1)
        this->GradeTooHighException();
    this->_grade--;
    std::cout << "Congratulations Bureaucrat " << this->_name << " on your promotion !" << std::endl;
}

void    Bureaucrat::Demote(void)
{
    if (this->_grade >= 150)
        this->GradeTooLowException();
    this->_grade++;
    std::cout << "Unfortunately Bureaucrat " << this->_name << " got demoted..." << std::endl; 
}

void    Bureaucrat::signAForm(AForm &AForm)
{
    try
    {
        AForm.beSigned(*this);
        std::cout << this->_name << " signed " << AForm.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->_name << " could'nt sign " << AForm.getName() << " because " << e.what();
    }
    
}

void    Bureaucrat::executeAForm(AForm const &Aform) const
{
    try
    {
        Aform.execute(*this);
    }
    catch(const std::exception& e)
    {
        std::cerr << this->_name << " can't execute form cause:" << e.what() << std::endl;
    }
    std::cout << this->_name << " Executed " << Aform.getName() << std::endl;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _grade(grade)
{
    if (grade == 0)
        this->GradeTooHighException();
    if (grade > 150)
        this->GradeTooHighException();
    std::cout << "Constructor for Bureaucrat " << this->_name << " called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy.getName()), _grade(copy.getGrade())
{
    std::cout << "Copy Constructor of Bureaucrat called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    std::cout << "Assignment operator of Bureaucrat called" << std::endl;
    if (this != &copy)
    {
        this->_grade = copy.getGrade();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Destructor for Bureaucrat " << this->_name << " called" << std::endl;
}