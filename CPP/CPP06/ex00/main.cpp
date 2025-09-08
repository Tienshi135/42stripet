#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " <value>" << std::endl;
		return 1;
	}
	
	ScalarConverter::convert(std::string(argv[1]));
	
	return 0;
}
