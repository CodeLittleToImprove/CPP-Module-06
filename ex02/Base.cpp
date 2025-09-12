#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Destructor
Base::~Base(void)
{
	// std::cout << "Destructor called" << std::endl;
}

Base *generate(void)
{
	int n = rand() % 3;
	switch (n)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			std::cout << "HOW? The range is 0 - 2" << std::endl;
			return (NULL);
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e) {}

	try
	{
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e) {}

	try
	{
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e) {}
}
