#pragma once

#include <iostream>

class ScalarConverter
{
protected:
	// Orthodox Canonical Form
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter& operator=(const ScalarConverter &copy);
	~ScalarConverter();
public:
	// Additional member functions go here
	static void convert(std::string input);
};
