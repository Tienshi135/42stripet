#include "BitcoinExchange.hpp"

void    printBitcoinMaps(BitcoinExchange    *bitcoin)
{
    std::map<std::string, float>    db = bitcoin->getDB();
    std::map<std::string, float>    inputDB = bitcoin->getInputDB();

    std::cout << "Database contents:" << std::endl;
    for (std::map<std::string, float>::iterator it = db.begin(); it != db.end(); ++it)
    {
        std::cout << it->first << " => " << it->second << std::endl;
    }

    std::cout << "\nInput Database contents:" << std::endl;
    for (std::map<std::string, float>::iterator it = inputDB.begin(); it != inputDB.end(); ++it)
    {
        std::cout << it->first << " => " << it->second << std::endl;
    }
}

int    main(int argc, char **argv)
{
    BitcoinExchange    *bitcoin;
    if (argc != 2)
    {
        std::cerr << "Error: usage: " << argv[0] << " <input.csv>" << std::endl;
        return (1);
    }
    try
    {
        bitcoin = new BitcoinExchange("data.csv", argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (1);
    }

    printBitcoinMaps(bitcoin);

    delete (bitcoin);
    return (0);
}