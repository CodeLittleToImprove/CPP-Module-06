#include "Base.hpp"

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

Base* generate(void)
{
	int n = rand() % 3;
	switch (n)
{
	case 0:
		{
			return (new A);
		}
	case 1:
	case 2:
}
}

