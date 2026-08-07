#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	(void)copy;
	return *this;
}

PmergeMe::~PmergeMe() {}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


template <typename Container>
void	PmergeMe::sort(Container &c)
{
	size_t		n;
	Container	mainChain;
	Container	pendingChain;
	bool		hasStraggler;
	int			straggler;
	size_t		i;

	n = c.size();
	if (n < 2)
		return;
	hasStraggler = false;
	straggler = 0;
	i = 0;
	while (i + 1 < n)
	{
		if (c[i] > c[i + 1])
		{
			mainChain.push_back(c[i]);
			pendingChain.push_back(c[i + 1]);
		}
		else
		{
			mainChain.push_back(c[i + 1]);
			pendingChain.push_back(c[i]);
		}
		i += 2;
	}
	if (i < n)
	{
		hasStraggler = true;
		straggler = c[i];
	}

	Container	preSortMain(mainChain.begin(), mainChain.end());
	sort(mainChain);

	mainChain.insert(mainChain.begin(),
		findPartner(preSortMain, pendingChain, mainChain.front()));

	size_t				pendCount;
	Container			sortedChain(mainChain.begin(), mainChain.end());

	pendCount = (sortedChain.size() >= 2) ? (sortedChain.size() - 2) : 0;
	Container	order;
	jacobsthalInsertOrder(pendCount, order);

	for (size_t o = 0; o < order.size(); ++o)
	{
		size_t	bIndex;
		int		bValue;
		int		smallValue;
		typename Container::iterator	boundIt;
		typename Container::iterator	insertPos;

		bIndex = static_cast<size_t>(order[o]);
		if (bIndex >= sortedChain.size())
			continue;
		bValue = sortedChain[bIndex];
		smallValue = findPartner(preSortMain, pendingChain, bValue);
		boundIt = std::find(mainChain.begin(), mainChain.end(), bValue);
		insertPos = std::lower_bound(mainChain.begin(), boundIt, smallValue);
		mainChain.insert(insertPos, smallValue);
	}

	if (hasStraggler)
	{
		typename Container::iterator	insertPos;

		insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(insertPos, straggler);
	}

	c.assign(mainChain.begin(), mainChain.end());
}

template void	PmergeMe::sort<std::vector<int> >(std::vector<int> &);
template void	PmergeMe::sort<std::deque<int> >(std::deque<int> &);

template <typename Container>
int	PmergeMe::findPartner(const Container &preSortMain,
					const Container &pendingChain, int large)
{
	typename Container::const_iterator	it;
	typename Container::const_iterator	pit;

	it = std::find(preSortMain.begin(), preSortMain.end(), large);
	pit = pendingChain.begin();
	std::advance(pit, std::distance(preSortMain.begin(), it));
	return *pit;
}


template <typename Container>
void	PmergeMe::jacobsthalInsertOrder(size_t pendCount, Container &order)
{
	size_t	inserted;
	size_t	prevJac;
	size_t	jac;

	if (pendCount == 0)
		return;
	inserted = 1;
	prevJac = 0;
	jac = 1;
	while (inserted < pendCount + 1)
	{
		size_t	nextJac;
		size_t	upper;

		nextJac = jac + 2 * prevJac;
		prevJac = jac;
		jac = nextJac;
		upper = jac;
		if (upper > pendCount + 1)
			upper = pendCount + 1;
		for (size_t idx = upper; idx > inserted; --idx)
			order.push_back(static_cast<int>(idx));
		inserted = upper;
	}
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

std::ostream	&operator<<(std::ostream &out, const std::vector<int> &v)
{
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
		out << *it << " ";
	return out;
}

std::ostream	&operator<<(std::ostream &out, const std::deque<int> &d)
{
	for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); ++it)
		out << *it << " ";
	return out;
}
