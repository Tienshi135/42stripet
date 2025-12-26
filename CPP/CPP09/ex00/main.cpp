#include "BitcoinExchange.hpp"

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
        bitcoin = new BitcoinExchange("data.csv");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (1);
    }

    bitcoin->processData(argv[1]);

    delete (bitcoin);
    return (0);
}