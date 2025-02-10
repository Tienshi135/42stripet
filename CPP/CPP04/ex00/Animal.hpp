/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:22:42 by stripet           #+#    #+#             */
/*   Updated: 2025/02/10 16:04:51 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(std::string type);
        virtual ~Animal();
        Animal(const Animal &copy);
        Animal &operator=(const Animal &copy);
        std::string getType() const;
        virtual void makeSound() const;
};