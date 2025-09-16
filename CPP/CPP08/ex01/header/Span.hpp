#pragma once

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <climits>
#include <cstdlib>


class SpanFullException : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Span is full, cannot add more numbers.";
	}
};

class Span
{
private:
	unsigned int	_n;
	unsigned int	_index;
	int				*_array;
public:
	Span(unsigned int n);
	Span(const Span &copy);
	Span &operator=(const Span &copy);
	~Span();

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	void	addNumber(int number);
	int		shortestSpan() const;
	int		longestSpan() const;
	void	printArray() const;
	void	fillArray();
};

