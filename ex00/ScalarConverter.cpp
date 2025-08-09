
#include "ScalarConverter.hpp"

#include <algorithm>

// Default constructor
ScalarConverter::ScalarConverter()
{
	// std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void) other;
	// std::cout << "Copy constructor called" << std::endl;
}

// Copy Assignment operator overload
ScalarConverter &ScalarConverter::operator=(const ScalarConverter& other)
{
	(void) other;
	// std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

// Destructor
ScalarConverter::~ScalarConverter(void)
{
	// std::cout << "Destructor called" << std::endl;
}

bool isAllAlphabetic(const std::string& str)
{
	for (std::size_t i = 0; i < str.size(); ++i)
	{
		if (isalpha(str[i]) == 0)
		{
			std::cout << str[i] << " is not alphabetic\n";
			return false;
		}
	}
	return true;
}

void ScalarConverter::convert(const std::string &input)
{
	bool isFloat = false;
	bool isChar = false;

	if (isAllAlphabetic(input))
	{
		isChar = true;
		std::cout << "is all alphabetic" << std::endl;
	}
	if (isChar && input.size() == 1)
	{
		char c = input[0];
	}

}
