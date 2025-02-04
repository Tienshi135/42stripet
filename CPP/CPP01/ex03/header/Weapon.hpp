/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:00:18 by tienshi           #+#    #+#             */
/*   Updated: 2024/12/12 14:06:03 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Weapon
{
private:
	std::string type;
public:
	Weapon(std::string type);
	~Weapon();
	const std::string& getType() const;
	void setType(std::string type);
};