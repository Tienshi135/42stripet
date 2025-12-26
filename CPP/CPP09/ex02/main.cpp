#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << "<numbers to sort>" << std::endl;
		return 1;
	}

	PmergeMe pmergeMe;
	pmergeMe.pMerge(&argv[1]);
	return 0;
}