#include "RPN.hpp"

RPN::RPN() : _stack()
{
}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
	if (this != &copy)
	{
		this->_stack = copy._stack;
	}
	return *this;
}

RPN::~RPN()
{
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

std::string intToStr(int num)
{
	std::stringstream	buffStream;
	std::string 		str;
	try {
		buffStream << num;
		buffStream >> str;
	} 
	catch (const std::exception &e) 
	{
		throw std::runtime_error("Error converting integer to string: " + std::string(e.what()));
	}
	return str;
}

int	strToInt(const std::string &str)
{
	try
	{
		std::stringstream	strStream(str);
		int					num;
		strStream >> num;
		if (strStream.fail() || !strStream.eof())
			throw std::runtime_error("Conversion failed");
		return num;
	}
	catch (const std::exception &)
	{
		throw std::runtime_error("Error: Invalid integer '" + str + "'");
	}
}

void	RPN::evaluate(std::string expression)//this function throws
{
	std::istringstream stream(expression);
	std::string token;
	while (std::getline(stream, token, ' '))
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error: Not enough operands for operation");
			int b = strToInt(_stack.top());//throw
			_stack.pop();
			int a = strToInt(_stack.top());//throw
			_stack.pop();
			int result;
			if (token == "+")
				result = a + b;
			else if (token == "-")
				result = a - b;
			else if (token == "*")
				result = a * b;
			else
			{
				if (b == 0)
					throw std::runtime_error("Error: Division by zero");
				result = a / b;
			}
			_stack.push(intToStr(result));//throw
		}
		else
		{
			int num;
			try
			{
				num = strToInt(token);//throw
			}
			catch (const std::invalid_argument &)
			{
				throw std::runtime_error("Error: Invalid token '" + token + "'");
			}
			if (num < 0 || num > 9)
					throw std::runtime_error("Error: Operand '" + token + "' out of range (0-9)");
			_stack.push(token);
		}
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error: The expression is invalid or incomplete");
	std::cout << strToInt(_stack.top()) << std::endl;//throw
}
