#include "BitcoinExchange.hpp"

int    main(int argc, char **argv)
{
    BitcoinExchange    *bitcoin;
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
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
    
    delete (bitcoin);
    return (0);
}