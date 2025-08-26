#include "ShrubberyCreationForm.hpp"
#include <fstream>

void    ShrubberyCreationForm::beExecuted(std::string target)
{
    std::ofstream file(target + "_shrubbery");
    file << "Printable ASCII [32..126]:\n";
    for (char c{' '}; c <= '~'; ++c)
        file << c << ((c + 1) % 32 ? ' ' : '\n');
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", target, 145, 137)
{
    std::cout << "Constructor for ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): AForm(copy)
{
    std::cout << "Copy Constructor for ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm  &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    std::cout << "assignment operator for ShrubberyCreationForm called" << std::endl;
    if (this == &copy)
        return (*this);
    AForm::operator=(copy);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Destructor for ShrubberyCreationForm called" << std::endl;
}
