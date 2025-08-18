/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:11:41 by stripet           #+#    #+#             */
/*   Updated: 2025/08/18 14:14:57 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

std::ostream    &operator<<(std::ostream &out, AForm &AForm)
{
    std::string status;

    status = "is signed.";
    if (AForm.getSigned() == false)
        status = "isn't signed.";
    out << AForm.getName() << " AForm status : " << status << std::endl << "Required level to sign : " << AForm.getSign() << " required level to execute : " << AForm.getExecute() << std::endl;
    return (out);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void AForm::GradeTooHighException(void) const
{
    throw (std::logic_error("Grade is too high\n"));
}

void AForm::GradeTooLowException(void) const
{
    throw (std::logic_error("Grade is too low\n"));
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

std::string		AForm::getName(void) const
{
    return (this->_Name);
}

bool			AForm::getSigned(void) const
{
    return (this->_Signed);
}

unsigned int	AForm::getSign(void) const
{
    return (this->_Sign);
}

unsigned int	AForm::getExecute(void) const
{
    return (this->_Execute);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void    AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getSign())
        this->GradeTooLowException();
    this->_Signed = true;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

AForm::AForm(std::string name, unsigned int sign, unsigned int execute): _Name(name), _Signed(false), _Sign(sign), _Execute(execute)
{
    if (sign == 0 || execute == 0)
        this->GradeTooHighException();
    if (sign > 150 || execute > 150)
        this->GradeTooHighException();
    std::cout << "Constructor for AForm " << this->_Name << " called" << std::endl;
}

AForm::AForm(const AForm &copy): _Name(copy.getName()), _Signed(copy.getSigned()), _Sign(copy.getSign()), _Execute(copy.getExecute())
{
    std::cout << "Copy Constructor of AForm called" << std::endl;
}

AForm    &AForm::operator=(const AForm &copy)
{
    std::cout << "Assignment operator of AForm called" << std::endl;
    if (this != &copy)
    {
        this->_Signed = copy.getSigned();
    }
    return (*this);
}

AForm::~AForm()
{
    std::cout << "Destructor for AForm " << this->_Name << " called" << std::endl;
}
