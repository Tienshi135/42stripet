#include <iostream>
#include <AForm.hpp>

class PresidentialPardonForm : public AForm
{
    private:

    public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &copy);
    PresidentialPardonForm  &operator=(const PresidentialPardonForm &copy);
    ~PresidentialPardonForm();
};
