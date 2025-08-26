#include "PresidentialPardonForm.hpp"

void    PresidentialPardonForm::beExecuted(std::string target)
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon", target, 25, 5)
{
    std::cout << "Constructor for PresidentialPardonForm called" << std::endl;

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): AForm(copy)
{
    std::cout << "Copy Constructor for PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm  &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    std::cout << "assignment operator for PresidentialPardonForm called" << std::endl;
    if (this == &copy)
		return (*this);
	AForm::operator=(copy);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor for PresidentialPardonForm called" << std::endl;
}
