#include "RobotomyRequestForm.hpp"
#include <cstdlib>

void    RobotomyRequestForm::beExecuted(std::string target) const
{
    int nb;

    std::cout << "* drilling noises *" << std::endl;
    nb = std::rand() % 2;
    if (nb == 0)
    {
        std::cout << "Robotomy failed... Please retry" << std::endl;
        return;
    }
    std::cout << target << " has been robotomized successfully" << std::endl;
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
