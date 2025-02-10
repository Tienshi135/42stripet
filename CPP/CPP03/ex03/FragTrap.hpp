/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:37:55 by stripet           #+#    #+#             */
/*   Updated: 2025/02/10 14:02:06 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap(const std::string name);
        ~FragTrap();
        FragTrap(const FragTrap &copy);
        FragTrap &operator=(const FragTrap &copy);
        void highFivesGuys();
};