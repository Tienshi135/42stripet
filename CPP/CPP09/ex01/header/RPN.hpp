#pragma once

#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
private:
	std::stack<std::string>	_stack;
public:
	RPN();
	RPN(const RPN &copy);
	RPN &operator=(const RPN &copy);
	~RPN();

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	void	evaluate(std::string expression);
};

