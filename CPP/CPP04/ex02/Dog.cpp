/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:23:11 by stripet           #+#    #+#             */
/*   Updated: 2025/02/10 16:10:28 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    this->_brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
    delete this->_brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = copy;
}

Dog &Dog::operator=(const Dog &copy)
{
    Animal::operator=(copy);
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &copy)
    {
        this->_type = copy._type;
        this->_brain = new Brain(*copy._brain);
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}

Brain *Dog::getBrain() const
{
    return this->_brain;
}
