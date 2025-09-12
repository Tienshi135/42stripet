#include "Serialize.hpp"

// Default constructor
Serialize::Serialize()
{
	std::cout << "Serialize default constructor called" << std::endl;
}

// Copy constructor
Serialize::Serialize(const Serialize &copy)
{
	std::cout << "Serialize copy constructor called" << std::endl;
	*this = copy;
}

// Assignment operator
Serialize& Serialize::operator=(const Serialize &copy)
{
	std::cout << "Serialize assignment operator called" << std::endl;
	if (this != &copy)
	{
		// Copy member variables from copy
		// Add your copying logic here
	}
	return *this;
}

// Destructor
Serialize::~Serialize()
{
	std::cout << "Serialize destructor called" << std::endl;
}

// Additional member function implementations go here

uintptr_t	Serialize::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data	*Serialize::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}