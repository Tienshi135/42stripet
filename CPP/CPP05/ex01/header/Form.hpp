/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:11:03 by stripet           #+#    #+#             */
/*   Updated: 2025/08/18 14:10:49 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat;

class Form
{
private:
    const std::string	_Name;
    bool				_Signed;
    const unsigned int	_Sign;
	const unsigned int	_Execute;
public:
    Form(std::string name, unsigned int sign, unsigned int execute);
	Form(const Form &copy);
	Form	&operator=(const Form &copy);
    ~Form();

	void	GradeTooHighException(void) const;
	void	GradeTooLowException(void) const;

	std::string		getName(void) const;
	bool			getSigned(void) const;
	unsigned int	getSign(void) const;
	unsigned int	getExecute(void) const;

	void	beSigned(Bureaucrat &bureaucrat);
};

std::ostream	&operator<<(std::ostream &out, Form &form);
