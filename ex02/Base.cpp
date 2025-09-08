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
	// srand(static_cast<unsigned int>(clock()));
	int n = rand() % 3;
	// std::cout << n << std::endl;
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
	catch (std::exception e) {}

	try
	{
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::exception e) {}

	try
	{
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::exception e) {}
}
