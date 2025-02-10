/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stripet <stripet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:30:45 by stripet           #+#    #+#             */
/*   Updated: 2025/02/10 16:18:19 by stripet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    int size = 10;
    Animal *Zoo[size];

    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
            Zoo[i] = new Dog();
        else
            Zoo[i] = new Cat();
    }

    for (int i = 0; i < size; i++)
    {
        Zoo[i]->makeSound();
        delete Zoo[i];
    }
    
    Cat *cat = new Cat();
    Cat *copy_cat = new Cat(*cat);
    Dog *dog = new Dog();
    Dog *copy_dog = new Dog(*dog);

    std::cout << "Cat's brain's memory address: " << cat->getBrain() << std::endl;
    std::cout << "Copy Cat's brain's memory address: " << copy_cat->getBrain() << std::endl;
    std::cout << "Dog's brain's memory address: " << dog->getBrain() << std::endl;
    std::cout << "Copy Dog's brain's memory address: " << copy_dog->getBrain() << std::endl;

    delete cat;
    delete copy_cat;
    delete dog;
    delete copy_dog;
    return 0;
}