#include "ScalarConverter.hpp"
#include <sstream>
#include <cctype>
#include <climits>
#include <cfloat>

enum LiteralType {
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_SPECIAL,
    TYPE_INVALID
};

// Default constructor
ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = copy;
}

// Assignment operator
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &copy)
{
	std::cout << "ScalarConverter assignment operator called" << std::endl;
	if (this != &copy)
	{
		// Copy member variables from other
		// Add your copying logic here
	}
	return *this;
}

// Destructor
ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

//helper functions
bool isInteger(const std::string& str) {
    if (str.empty()) return false;
    size_t start = 0;
    if (str[0] == '+' || str[0] == '-') start = 1;
    if (start >= str.length()) return false;
    
    for (size_t i = start; i < str.length(); ++i) {
        if (!std::isdigit(str[i])) return false;
    }
    return true;
}

bool isChar(const std::string& str) {
    // Check for single printable character (non-digit)
    if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0])) {
        return true;
    }
    return false;
}

bool isFloat(const std::string& str) {
    if (str.length() <= 1) return false;
    if (str[str.length() - 1] != 'f') return false;
    
    std::string withoutF = str.substr(0, str.length() - 1);
    std::istringstream iss(withoutF);
    float value;
    std::string remainder;
    return (iss >> value) && !(iss >> remainder);
}

bool isDouble(const std::string& str) {
    if (str.find('.') == std::string::npos) return false;
    
    std::istringstream iss(str);
    double value;
    std::string remainder;
    return (iss >> value) && !(iss >> remainder);
}

bool isSpecial(const std::string& str) {
    return (str == "nan" || str == "nanf" || 
            str == "inf" || str == "inff" || str == "+inf" || str == "+inff" ||
            str == "-inf" || str == "-inff");
}

LiteralType getType(const std::string& input) {
    if (input.empty()) return TYPE_INVALID;
    
    if (isChar(input)) return TYPE_CHAR;
    if (isSpecial(input)) return TYPE_SPECIAL;
    if (isFloat(input)) return TYPE_FLOAT;
    if (isDouble(input)) return TYPE_DOUBLE;
    if (isInteger(input)) return TYPE_INT;
    
    return TYPE_INVALID;
}

void printFromChar(const std::string& input) {
    char c = input[0]; // Single character
    
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void printFromInt(const std::string& input) {
    std::istringstream iss(input);
    int value;
    iss >> value;
    
    // Print char
    if (value >= 0 && value <= 127 && std::isprint(value)) {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    } else if (value >= 0 && value <= 127) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: impossible" << std::endl;
    }
    
    std::cout << "int: " << value << std::endl;
    std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void printFromFloat(const std::string& input) {
    std::string withoutF = input.substr(0, input.length() - 1);
    std::istringstream iss(withoutF);
    float value;
    iss >> value;
    
    // Print char
    if (value >= 0 && value <= 127 && value == static_cast<int>(value) && std::isprint(static_cast<int>(value))) {
        std::cout << "char: '" << static_cast<char>(static_cast<int>(value)) << "'" << std::endl;
    } else if (value >= 0 && value <= 127 && value == static_cast<int>(value)) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: impossible" << std::endl;
    }
    
    // Print int
    if (value >= static_cast<float>(INT_MIN) && value <= static_cast<float>(INT_MAX)) {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    } else {
        std::cout << "int: impossible" << std::endl;
    }
    
    std::cout << "float: " << value << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void printFromDouble(const std::string& input) {
    std::istringstream iss(input);
    double value;
    iss >> value;
    
    // Print char
    if (value >= 0 && value <= 127 && value == static_cast<int>(value) && std::isprint(static_cast<int>(value))) {
        std::cout << "char: '" << static_cast<char>(static_cast<int>(value)) << "'" << std::endl;
    } else if (value >= 0 && value <= 127 && value == static_cast<int>(value)) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: impossible" << std::endl;
    }
    
    // Print int
    if (value >= static_cast<double>(INT_MIN) && value <= static_cast<double>(INT_MAX)) {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    } else {
        std::cout << "int: impossible" << std::endl;
    }
    
    // Print float
    if (value >= -FLT_MAX && value <= FLT_MAX) {
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    } else {
        std::cout << "float: impossible" << std::endl;
    }
    
    std::cout << "double: " << value << std::endl;
}

void printFromSpecial(const std::string& input) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    
    if (input == "nan" || input == "nanf") {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } else if (input == "inf" || input == "inff" || input == "+inf" || input == "+inff") {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    } else if (input == "-inf" || input == "-inff") {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

// Additional member function implementations go here
void ScalarConverter::convert(std::string input)
{
    LiteralType type = getType(input);

	std::cout << "input is: " << input << std::endl << std::endl;
	switch (type)
	{
	case TYPE_CHAR:
		printFromChar(input);
		break;
	case TYPE_INT:
		printFromInt(input);
		break;
	case TYPE_FLOAT:
		printFromFloat(input);
		break;
	case TYPE_DOUBLE:
		printFromDouble(input);
		break;
	case TYPE_SPECIAL:
		printFromSpecial(input);
		break;
	default:
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		break;
	}
}