#include "Span.hpp"

Span::Span(unsigned int n) : _n(n), _index(0)
{
	this->_array = new int[this->_n];
	std::cout << "Span parameterized constructor called with size " << n << std::endl;
}

Span::Span(const Span &copy) : _n(copy._n), _index(copy._index)
{
	std::cout << "Span copy constructor called" << std::endl;
	this->_array = new int[this->_n];
	for (unsigned int i = 0; i < this->_n; i++)
		this->_array[i] = copy._array[i];	
}

Span &Span::operator=(const Span &copy)
{
	std::cout << "Span assignment operator called" << std::endl;
	if (this != &copy)
	{
		delete[] this->_array;
		this->_n = copy._n;
		this->_index = copy._index;
		this->_array = new int[this->_n];
		for (unsigned int i = 0; i < this->_n; i++)
			this->_array[i] = copy._array[i];
	}
	return *this;
}

Span::~Span()
{
	delete[] this->_array;
	std::cout << "Span destructor called" << std::endl;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void	Span::addNumber(int number)
{
	if (this->_index >= this->_n)
		throw SpanFullException();
	this->_array[this->_index] = number;
	this->_index++;
}

int	Span::shortestSpan() const
{
	if (this->_index < 2)
		throw std::runtime_error("Not enough numbers to find a span.");
	
	int minSpan = INT_MAX;
	int *sortedArray = new int[this->_index];
	std::copy(this->_array, this->_array + this->_index, sortedArray);
	std::sort(sortedArray, sortedArray + this->_index);
	
	for (unsigned int i = 0; i < this->_index - 1; i++)
	{
		int span = sortedArray[i + 1] - sortedArray[i];
		if (span < minSpan)
			minSpan = span;
	}
	
	delete[] sortedArray;
	return minSpan;
}

int	Span::longestSpan() const
{
	if (this->_index < 2)
		throw std::runtime_error("Not enough numbers to find a span.");
	
	int minVal = *std::min_element(this->_array, this->_array + this->_index);
	int maxVal = *std::max_element(this->_array, this->_array + this->_index);
	return maxVal - minVal;
}

void	Span::printArray() const
{
	std::cout << "Array contents: ";
	for (unsigned int i = 0; i < this->_index; i++)
		std::cout << this->_array[i] << " ";
	std::cout << std::endl;
}

void	Span::fillArray()
{
	rand();
	for (unsigned int i = 0; i < this->_n; i++)
	{
		int num = rand() % INT_MAX;
		this->addNumber(num);
	}
}