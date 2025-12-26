#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

class BitcoinExchange
{

	private:
		std::map	<std::string, float> _DB;
	public:
		BitcoinExchange(std::string dbFile);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		~BitcoinExchange();

		std::map<std::string, float>	getDB() const { return this->_DB; }

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

		void	processData(std::string inputFile);
};