#include "BitcoinExchange.hpp"

void	parseLine(std::map<std::string, float> &db, const std::string &line)
{
	std::map<std::string, float>	buffer;

	std::istringstream	lineStream(line);
	std::string			date;
	std::string			valueStr;
	if (std::getline(lineStream, date, ',') && std::getline(lineStream, valueStr))
	{
		if (date.empty() || valueStr.empty())
		{
			throw std::runtime_error("Error: empty date or value in line: " + line);
		}
		try
		{
			float	value;
			std::stringstream valueStream(valueStr);
			valueStream >> value;
			if (valueStream.fail() || !valueStream.eof())
				throw std::runtime_error("An error occured during value conversion.");
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


BitcoinExchange::BitcoinExchange(std::string dbFile)
{
	std::ifstream	dbStream(dbFile.c_str());

	if (!dbStream.is_open())
	{
		throw std::runtime_error("Error: could not open file.");
	}
	std::string	line;
	std::getline(dbStream, line); //skip header
	while (std::getline(dbStream, line))
	{
		parseLine(this->_DB, line);//THIS FUNCTION THROWS
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
	{
		this->_DB = copy.getDB();
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

bool validateDate(std::string &date)
{
	date = date.erase(date.find_last_not_of(" \n\r\t") + 1);
	std::istringstream	lineStream(date);

	int	year, month, day;

	if (date.length() > 10)
		return false;
	try {
		char	dash1, dash2;
		lineStream >> year >> dash1 >> month >> dash2 >> day;
		if (lineStream.fail() || dash1 != '-' || dash2 != '-')
			return false;
		if (month < 1 || month > 12 || day < 1 || day > 31)
			return false;
	} catch (std::exception &e) {
		return false;
	}
	return true;
}


void	BitcoinExchange::processData(std::string inputFile)
{
	std::ifstream	inputStream(inputFile.c_str());
	if (!inputStream.is_open())
	{
		throw std::runtime_error("Error: could not open input file.");
	}
	std::string	line;
	std::getline(inputStream, line); //skip header
	while (std::getline(inputStream, line))
	{
		std::istringstream	lineStream(line);
		std::string			date;
		std::string			valueStr;
		float				value;
		if (std::getline(lineStream, date, '|') && std::getline(lineStream, valueStr))
		{
			if (date.empty() || valueStr.empty())
			{
				std::cout << "Error: bad input => " << date << std::endl;
				continue;
			}
			try {
				std::stringstream valueStream(valueStr);
				valueStream >> value;
				if (valueStream.fail() || !valueStream.eof())
					throw std::runtime_error("An error occured during value conversion.");
			} catch (const std::exception &e) {
				std::cout << "Error: bad input => " << date << std::endl;
				continue;
			}
			if (!validateDate(date))
			{
				std::cout << "Error: bad input => " << date << std::endl;
				continue;
			}
			if (value < 0)
			{
				std::cout << "Error: not a positive number." << std::endl;
				continue;
			}
			if (value > 1000)
			{
				std::cout << "Error: too large a number." << std::endl;
				continue;
			}
			std::map<std::string, float>::iterator found = _DB.lower_bound(date);
			if (found == _DB.begin() && found->first != date)
			{
				std::cout << "Bad input => " << date << std::endl;
				continue;
			}
			if (found == _DB.end())
				--found;
			else if (found->first != date)
				--found;
			std::cout << date << " => " << value << " = " << value * found->second << std::endl;
		}
		else
		{
			std::cout << "Invalid line" << date << std::endl;
		}
	}
}