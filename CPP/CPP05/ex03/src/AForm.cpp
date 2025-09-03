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
    return (this->_name);
}

std::string	AForm::getTarget(void) const
{
	return (this->_target);
}

bool	AForm::getSigned(void) const
{
    return (this->_signed);
}

unsigned int	AForm::getSign(void) const
{
    return (this->_sign);
}

unsigned int	AForm::getExecute(void) const
{
    return (this->_execute);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void    AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getSign())
        this->GradeTooLowException();
    this->_signed = true;
}

void    AForm::execute(Bureaucrat const &bureaucrat) const
{
    if (!this->_signed)
    {
        throw (std::logic_error("Form is not signed"));
        return;
    }
    if (bureaucrat.getGrade() > this->_execute)
    {
        bureaucrat.GradeTooLowException();
        return;
    }
    this->beExecuted(this->_target);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

AForm::AForm(std::string name, std::string target, unsigned int sign, unsigned int execute):_name(name), _target(target), _sign(sign), _execute(execute)
{
    if (sign == 0 || execute == 0)
        this->GradeTooHighException();
    if (sign > 150 || execute > 150)
        this->GradeTooHighException();
    this->_signed = false;
    std::cout << "Constructor for AForm " << this->_name << " called" << std::endl;
}

AForm::AForm(const AForm &copy): _name(copy.getName()), _target(copy.getTarget()), _signed(copy.getSigned()), _sign(copy.getSign()), _execute(copy.getExecute())
{
    std::cout << "Copy Constructor of AForm called" << std::endl;
}

AForm    &AForm::operator=(const AForm &copy)
{
    std::cout << "Assignment operator of AForm called" << std::endl;
    if (this != &copy)
    {
        this->_signed = copy.getSigned();
    }
    return (*this);
}

AForm::~AForm()
{
    std::cout << "Destructor for AForm " << this->_name << " called" << std::endl;
}
