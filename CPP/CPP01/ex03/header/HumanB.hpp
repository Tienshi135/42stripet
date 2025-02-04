/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:14:53 by tienshi           #+#    #+#             */
/*   Updated: 2024/12/12 14:15:13 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	Weapon* weapon;
public:
	HumanB(std::string name);
	~HumanB();
	void attack();
	void setWeapon(Weapon& weapon);
};