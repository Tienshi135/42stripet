/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:11:41 by stripet           #+#    #+#             */
/*   Updated: 2025/08/18 14:14:57 by stripet          ###   ########.fr       */
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
    return (this->_Name);
}

bool			Form::getSigned(void) const
{
    return (this->_Signed);
}

unsigned int	Form::getSign(void) const
{
    return (this->_Sign);
}

unsigned int	Form::getExecute(void) const
{
    return (this->_Execute);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void    Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getSign())
        this->GradeTooLowException();
    this->_Signed = true;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Form::Form(std::string name, unsigned int sign, unsigned int execute): _Name(name), _Signed(false), _Sign(sign), _Execute(execute)
{
    if (sign == 0 || execute == 0)
        this->GradeTooHighException();
    if (sign > 150 || execute > 150)
        this->GradeTooHighException();
    std::cout << "Constructor for Form " << this->_Name << " called" << std::endl;
}

Form::Form(const Form &copy): _Name(copy.getName()), _Signed(copy.getSigned()), _Sign(copy.getSign()), _Execute(copy.getExecute())
{
    std::cout << "Copy Constructor of Form called" << std::endl;
}

Form    &Form::operator=(const Form &copy)
{
    std::cout << "Assignment operator of Form called" << std::endl;
    if (this != &copy)
    {
        this->_Signed = copy.getSigned();
    }
    return (*this);
}

Form::~Form()
{
    std::cout << "Destructor for Form " << this->_Name << " called" << std::endl;
}
