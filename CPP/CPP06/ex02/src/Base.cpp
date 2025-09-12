#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base::~Base()
{
	std::cout << "Base destructor called" << std::endl;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Base	*Base::generate(void)
{
	Base	*ret;
	int		nb;

	nb = std::rand();
	if (nb % 2 == 0)
	{
		ret = new A();
	}
	else if (nb % 3 == 0)
	{
		ret = new B();
	}
	else
	{
		ret = new C();
	}
	return (ret);
}
void	Base::identify(Base *p)
{
    if (dynamic_cast<A*>(p))
	{
        std::cout << "A" << std::endl;
    }
	else if (dynamic_cast<B*>(p))
	{
        std::cout << "B" << std::endl;
    }
	else if (dynamic_cast<C*>(p))
	{
        std::cout << "C" << std::endl;
    }
}

void	Base::identify(Base &p)
{
	try {
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (std::exception &e) {
	}
	
	try {
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (std::exception &e) {
	}
	
	try {
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (std::exception &e) {
		std::cout << "Unknown type" << std::endl;
	}
}