/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:11:41 by stripet           #+#    #+#             */
/*   Updated: 2025/08/20 14:40:28 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

std::ostream    &operator<<(std::ostream &out, Form &form)
{
    std::string status;

    status = "is signed.";
    if (form.getSigned() == false)
        status = "isn't signed.";
    out << form.getName() << " form status : " << status << std::endl << "Required level to sign : " << form.getSign() << " required level to execute : " << form.getExecute() << std::endl;
    return (out);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void Form::GradeTooHighException(void) const
{
    throw (std::logic_error("Grade is too high\n"));
}

void Form::GradeTooLowException(void) const
{
    throw (std::logic_error("Grade is too low\n"));
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

std::string		Form::getName(void) const
{
    return (this->_name);
}

bool			Form::getSigned(void) const
{
    return (this->_signed);
}

unsigned int	Form::getSign(void) const
{
    return (this->_sign);
}

unsigned int	Form::getExecute(void) const
{
    return (this->_execute);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void    Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getSign())
        this->GradeTooLowException();
    this->_signed = true;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Form::Form(std::string name, unsigned int sign, unsigned int execute): _name(name), _signed(false), _sign(sign), _execute(execute)
{
    if (sign == 0 || execute == 0)
        this->GradeTooHighException();
    if (sign > 150 || execute > 150)
        this->GradeTooHighException();
    std::cout << "Constructor for Form " << this->_name << " called" << std::endl;
}

Form::Form(const Form &copy): _name(copy.getName()), _signed(copy.getSigned()), _sign(copy.getSign()), _execute(copy.getExecute())
{
    std::cout << "Copy Constructor of Form called" << std::endl;
}

Form    &Form::operator=(const Form &copy)
{
    std::cout << "Assignment operator of Form called" << std::endl;
    if (this != &copy)
    {
        this->_signed = copy.getSigned();
    }
    return (*this);
}

Form::~Form()
{
    std::cout << "Destructor for Form " << this->_name << " called" << std::endl;
}
