#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{
    std::cout << "Constructor for RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
{
    std::cout << "Copy Constructor for RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm  &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    std::cout << "assignment operator for RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Destructor for RobotomyRequestForm called" << std::endl;
}
