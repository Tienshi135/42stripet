#pragma once

#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>
#include <stdexcept>

class PmergeMe
{

public:
	PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &copy);
	~PmergeMe();

	template <typename Container>
	void	sort(Container &c);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

private:
	template <typename Container>
	int		findPartner(const Container &preSortMain,
					const Container &pendingChain, int large);
	template <typename Container>
	void	jacobsthalInsertOrder(size_t pendCount, Container &order);
};

std::ostream	&operator<<(std::ostream &out, const std::vector<int> &v);
std::ostream	&operator<<(std::ostream &out, const std::deque<int> &d);
