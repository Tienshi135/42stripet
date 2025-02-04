/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:44:03 by tienshi           #+#    #+#             */
/*   Updated: 2024/12/17 22:07:39 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Harl
{
public:
	Harl();
	~Harl();
	void    complain( std::string level );
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};