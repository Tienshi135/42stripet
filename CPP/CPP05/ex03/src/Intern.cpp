#include "Intern.hpp"

typedef	AForm* (*fnct_ptr)(const std::string& target);

AForm* createPresidential(const std::string& target) { return new PresidentialPardonForm(target); }
AForm* createRobotomy(const std::string& target) { return new RobotomyRequestForm(target); }
AForm* createShrubbery(const std::string& target) { return new ShrubberyCreationForm(target); }

AForm   *Intern::makeForm(std::string name, std::string target)
{
	AForm		*ret;
	std::string	identifier[3] = {"presidential pardon request", "robotomy request", "shrubbery request"};
	fnct_ptr	ptr[3] = {&createPresidential, &createRobotomy, &createShrubbery};

	for (int i = 0; i < 3; i++)
	{
		if (identifier[i] == name)
		{
			ret = ptr[i](target);
			std::cout << "intern creates " << ret->getName() << std::endl;
			return (ret);
		}
	}
	std::cout << "Can't create form" << std::endl;
	throw std::runtime_error("No form match that name");
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Intern::Intern()
{
    std::cout << "Constructor for Intern called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
    std::cout << "Copy Constructor for Intern called" << std::endl;
	*this = copy;
}

Intern  &Intern::operator=(const Intern &copy)
{
    std::cout << "assignment operator for Intern called" << std::endl;
	if (this == &copy)
		return (*this);
	*this = copy;
	return (*this);
}

Intern::~Intern()
{
    std::cout << "Destructor for Intern called" << std::endl;
}
