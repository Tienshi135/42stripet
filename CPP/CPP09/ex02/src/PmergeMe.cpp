#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _input(), _mainQueue(), _pendingQueue()
{
	std::cout << "PmergeMe default constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	std::cout << "PmergeMe copy constructor called" << std::endl;
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	std::cout << "PmergeMe assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->_input = copy._input;
		this->_mainQueue = copy._mainQueue;
		this->_pendingQueue = copy._pendingQueue;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe destructor called" << std::endl;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void	FordJohnson(std::queue<int> &input,
							std::queue<int> &mainQueue,
							std::queue<int> &pendingQueue)
{
	(void)pendingQueue; // Unused for now
	// Simple sort using std::sort for demonstration purposes
	std::vector<int>	tempVec;
	input = mainQueue;
}

void	PmergeMe::pMerge(char **input)
{
	for (int i = 0; input[i]; ++i)
	{
		std::stringstream	stream;
		int					num;
		try {
			stream << input[i];
			stream >> num;
			if (stream.fail() || !stream.eof())
				throw std::runtime_error("Invalid number");
			if (std::find(this->_input.front(), this->_input.back(), num) != this->_input.back())
				throw std::runtime_error("Duplicate number");
			this->_input.push(num);
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << " : " << input[i] << std::endl;
			return;
		}
	}
	std::cout << "Input numbers: ";
	this->printIntQueue(this->_input);
	FordJohnson(this->_input, this->_mainQueue, this->_pendingQueue);
}

void	PmergeMe::printIntQueue(const std::queue<int> toprint) const
{
	std::queue<int>	copy = toprint;

	while (!copy.empty())
	{
		std::cout << copy.front() << " ";
		copy.pop();
	}
	std::cout << std::endl;
}
