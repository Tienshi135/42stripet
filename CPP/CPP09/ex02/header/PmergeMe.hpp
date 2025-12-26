#pragma once

#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <exception>
#include <algorithm>

class PmergeMe
{
private:
	std::queue<int>	_input;
	std::queue<int>	_mainQueue;
	std::queue<int>	_pendingQueue;

public:
	PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &copy);
	~PmergeMe();

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	void		pMerge(char **input);
	void		printIntQueue(const std::queue<int> toprint) const;
};

