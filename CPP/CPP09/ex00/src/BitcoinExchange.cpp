#include "BitcoinExchange.hpp"

void	parseLine(std::map<std::string, float> &db, const std::string &line)
{

}

BitcoinExchange::BitcoinExchange(std::string dbFile, std::string inputFile)
{
	std::ifstream	dbStream(dbFile.c_str());
	std::ifstream	inputStream(inputFile.c_str());

	if (!dbStream.is_open() || !inputStream.is_open())
	{
		throw std::runtime_error("Error: could not open file.");
	}
	std::string	line;;
	while (std::getline(dbStream, line))
	{
		parseLine(this->_DB, line);//THIS FUNCTION THROWS
	}
	while (std::getline(inputStream, line))
	{
		parseLine(this->_inputDB, line);//THIS FUNCTION THROWS
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	std::cout << "BitcoinExchange copy constructor called" << std::endl;
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	std::cout << "BitcoinExchange assignment operator called" << std::endl;
	if (this != &copy)
	{

	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange destructor called" << std::endl;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
