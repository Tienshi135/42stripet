#pragma once

#include <iostream>
#include <map>
#include <functional>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
    Intern();
    Intern(const Intern &copy);
    Intern  &operator=(const Intern &copy);
    ~Intern();

    AForm   *makeForm(std::string name, std::string target);
};
