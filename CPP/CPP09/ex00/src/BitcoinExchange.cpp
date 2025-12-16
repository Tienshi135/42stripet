#include "BitcoinExchange.hpp"

void	parseLine(std::map<std::string, float> &db, const std::string &line)
{
	std::map<std::string, float>	buffer;

	std::istringstream	lineStream(line);
	std::string			date;
	std::string			valueStr;
	if (std::getline(lineStream, date, ',') && std::getline(lineStream, valueStr))
	{
		try
		{
			float	value = std::stof(valueStr);
			db[date] = value;
		}
		catch (const std::exception &e)
		{
			throw std::runtime_error("Error: invalid value in line: " + line);
		}
	}
	else
	{
		throw std::runtime_error("Error: invalid line format: " + line);
	}
}

BitcoinExchange::BitcoinExchange(std::string dbFile, std::string inputFile)
{
	std::ifstream	dbStream(dbFile.c_str());
	std::ifstream	inputStream(inputFile.c_str());

	if (!dbStream.is_open() || !inputStream.is_open())
	{
		throw std::runtime_error("Error: could not open file.");
	}
	std::string	line;
	std::getline(dbStream, line); //skip header
	while (std::getline(dbStream, line))
	{
		parseLine(this->_DB, line);//THIS FUNCTION THROWS
	}
	std::getline(inputStream, line); //skip header
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
