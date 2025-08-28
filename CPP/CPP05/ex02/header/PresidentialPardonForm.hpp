#pragma once

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &copy);
    PresidentialPardonForm  &operator=(const PresidentialPardonForm &copy);
    ~PresidentialPardonForm();

    void    beExecuted(std::string target) const;
};
