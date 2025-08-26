#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPadkhasbdajs", target, 145, 137)
{
    std::cout << "Constructor for PresidentialPardonForm called" << std::endl;

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
{
    std::cout << "Copy Constructor for PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm  &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    std::cout << "assignment operator for PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor for PresidentialPardonForm called" << std::endl;
}
