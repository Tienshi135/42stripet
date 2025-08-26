#include "RobotomyRequestForm.hpp"
#include <cstdlib>

void    RobotomyRequestForm::beExecuted(std::string target)
{
    int nb;

    nb = std::rand() % 100;
    if (nb >= 50)
    {
        std::cout << "Robotomy failed... Please retry" << std::endl;
        return;
    }
    std::cout << "Dzzzz Dzzzz Dzzzzz" << std::endl << "..." << std::endl << target << " has been robotomized" << std::endl;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", target, 72, 45)
{
    std::cout << "Constructor for RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): AForm(copy)
{
    std::cout << "Copy Constructor for RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm  &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    std::cout << "assignment operator for RobotomyRequestForm called" << std::endl;
    if (this == &copy)
        return (*this);
    AForm::operator=(copy);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Destructor for RobotomyRequestForm called" << std::endl;
}
