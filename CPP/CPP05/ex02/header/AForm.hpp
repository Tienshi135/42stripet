/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:11:03 by stripet           #+#    #+#             */
/*   Updated: 2025/08/18 14:57:40 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat;

class AForm
{
private:
    const std::string	_name;
	const std::string	_target;
    bool				_signed;
    const unsigned int	_sign;
	const unsigned int	_execute;
public:
    AForm(std::string name, std::string target, unsigned int sign, unsigned int execute);
	AForm(const AForm &copy);
	AForm	&operator=(const AForm &copy);
    ~AForm();

	void	GradeTooHighException(void) const;
	void	GradeTooLowException(void) const;

	std::string		getName(void) const;
	std::string		getTarget(void) const;
	bool			getSigned(void) const;
	unsigned int	getSign(void) const;
	unsigned int	getExecute(void) const;

	virtual void	beSigned(Bureaucrat &bureaucrat) = 0;
};

std::ostream	&operator<<(std::ostream &out, AForm &AForm);
