#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// // Default constructor
// Base::Base()
// {
// 	// std::cout << "Default constructor called" << std::endl;
// }
//
// // Copy constructor
// Base::Base(const Base &other)
// {
// 	(void) other;
// 	// std::cout << "Copy constructor called" << std::endl;
// }
//
// // Copy Assignment operator overload
// Base &Base::operator=(const Base &other)
// {
// 	(void) other;
// 	// std::cout << "Copy assignment operator called" << std::endl;
// 	return (*this);
// }

// Destructor
Base::~Base(void)
{
	// std::cout << "Destructor called" << std::endl;
}

Base *generate(void)
{
	srand(time(NULL));
	int n = rand() % 3;
	std::cout << n << std::endl;
	switch (n)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			std::cout << "HOW? The Range is 0 - 2" << std::endl;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception e)
	{
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception e)
	{
	}
	try
	{
		C &b = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::exception e)
	{
		// dynamic_cast<C *>(&p);
	}
}
