#include <iostream>
#include <AForm.hpp>

class RobotomyRequestForm : public AForm
{
    private:

    public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &copy);
    RobotomyRequestForm  &operator=(const RobotomyRequestForm &copy);
    ~RobotomyRequestForm();
};
