#include <iostream>
#include <AForm.hpp>

class ShrubberyCreationForm : public AForm
{
    public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &copy);
    ShrubberyCreationForm  &operator=(const ShrubberyCreationForm &copy);
    ~ShrubberyCreationForm();

    void    beExecuted(std::string target);
};
