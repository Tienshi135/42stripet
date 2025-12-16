#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

class BitcoinExchange
{

	private:
		std::map	<std::string, float> _DB;
		std::map	<std::string, float> _inputDB;
	public:
		BitcoinExchange(std::string dbFile, std::string inputFile);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);
		~BitcoinExchange();

		std::map<std::string, float>	getInputDB() const { return this->_inputDB; }
		std::map<std::string, float>	getDB() const { return this->_DB; }
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		void	processData();
};

