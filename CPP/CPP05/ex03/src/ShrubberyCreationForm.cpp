#include "ShrubberyCreationForm.hpp"
#include <fstream>

void    ShrubberyCreationForm::beExecuted(std::string target) const
{
    std::ofstream file((target + std::string("_shrubbery")).c_str());
    file << "       _-_\n";
    file << "    /~~   ~~\\\n";
    file << " /~~         ~~\\\n";
    file << "{               }\n";
    file << " \\  _-     -_  /\n";
    file << "   ~  \\\\ //  ~\n";
    file << "_- -   | | _- _\n";
    file << "  _ -  | |   -_\n";
    file << "      // \\\\\n";
    file << "ASCII Art Tree" << std::endl;
    file.close();
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
