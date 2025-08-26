/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:39:04 by stripet           #+#    #+#             */
/*   Updated: 2025/08/20 14:39:33 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
    return (this->_Grade);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void    Bureaucrat::Promote(void)
{
    if (this->_Grade <= 1)
        this->GradeTooHighException();
    this->_Grade--;
    std::cout << "Congratulations Bureaucrat " << this->_name << " on your promotion !" << std::endl;
}

void    Bureaucrat::Demote(void)
{
    if (this->_Grade >= 150)
        this->GradeTooLowException();
    this->_Grade++;
    std::cout << "Unfortunately Bureaucrat " << this->_name << " got demoted..." << std::endl; 
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _Grade(grade)
{
    if (grade == 0)
        this->GradeTooHighException();
    if (grade > 150)
        this->GradeTooHighException();
    std::cout << "Constructor for Bureaucrat " << this->_name << " called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy.getName()), _Grade(copy.getGrade())
{
    std::cout << "Copy Constructor of Bureaucrat called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    std::cout << "Assignment operator of Bureaucrat called" << std::endl;
    if (this != &copy)
    {
        this->_Grade = copy.getGrade();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Destructor for Bureaucrat " << this->_name << " called" << std::endl;
}