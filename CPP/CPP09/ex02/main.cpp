#include "PmergeMe.hpp"
#include <sys/time.h>

static long	microsSince(const struct timeval &start)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return (end.tv_sec - start.tv_sec) * 1000000L
			+ (end.tv_usec - start.tv_usec);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <numbers to sort>" << std::endl;
		return 1;
	}
	PmergeMe 			pmergeMe;
	std::vector<int>	vector_list;
	std::deque<int>		deque_list;

	for (int i = 1; i < argc; i++)
	{
		std::stringstream	stream;
		int					num;

		try {
			stream << argv[i];
			stream >> num;
			if (stream.fail() || !stream.eof())
				throw std::runtime_error("invalid number");
			if (std::find(vector_list.begin(), vector_list.end(), num) != vector_list.end()
				|| std::find(deque_list.begin(), deque_list.end(), num) != deque_list.end())
				throw std::runtime_error("duplicate numbers");
			vector_list.push_back(num);
			deque_list.push_back(num);
		}	catch(const std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
			return 1;
		}
	}
	struct timeval	start;

	std::cout << "Vector before sort: " << vector_list << std::endl;
	gettimeofday(&start, NULL);
	pmergeMe.sort(vector_list);
	long	vectorTime = microsSince(start);
	std::cout << "Vector after sort:  " << vector_list << std::endl;

	std::cout << "Deque before sort:  " << deque_list << std::endl;
	gettimeofday(&start, NULL);
	pmergeMe.sort(deque_list);
	long	dequeTime = microsSince(start);
	std::cout << "Deque after sort:   " << deque_list << std::endl;

	std::cout << "Time to process a range of " << vector_list.size()
				<< " elements with std::vector : " << vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << deque_list.size()
				<< " elements with std::deque : " << dequeTime << " us" << std::endl;
	return 0;
}