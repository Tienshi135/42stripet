/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:39:06 by stripet           #+#    #+#             */
/*   Updated: 2025/08/20 14:39:33 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_Grade;
	public:
		Bureaucrat(std::string name, unsigned int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat	&operator=(const Bureaucrat &copy);

		void	GradeTooHighException(void) const;
		void	GradeTooLowException(void) const;

		std::string		getName(void) const;
		unsigned int	getGrade(void) const;

		void	Promote(void);
		void	Demote(void);
		void	signForm(Form &form);
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat);