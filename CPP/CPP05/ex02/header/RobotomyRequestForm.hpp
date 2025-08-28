#pragma once

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &copy);
    RobotomyRequestForm  &operator=(const RobotomyRequestForm &copy);
    ~RobotomyRequestForm();

    void    beExecuted(std::string target) const;
};
