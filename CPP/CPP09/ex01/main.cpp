#include "RPN.hpp"

int main(int argc, char **argv)
{
	RPN rpnCalculator;

	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <RPN expression>" << std::endl;
		return 1;
	}
	try {
		rpnCalculator.evaluate(argv[1]);
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}