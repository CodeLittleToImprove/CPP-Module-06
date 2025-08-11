
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
		std::cout << c << std::endl;
		return ;
	}
	char* notNumeric;
	// std::cout << "pre strtod: " << notNumeric << std::endl;
	long double floatNbr = strtod(input.c_str(), &notNumeric); // string to double
	if (*notNumeric != '\0')
	{
		std::cout << "not strict numeric: " << notNumeric << std::endl;
	}
	double intpart;
	int intNbr = modf(floatNbr, &intpart);
	std::cout << "floatNbr: " << floatNbr << std::endl;
	std::cout << "intpart: " << intpart << std::endl;
	if (ceil(floatNbr) != floor(intpart))
	{
		std::cout << "ceil: " << ceil(floatNbr) << std::endl;
		std::cout << "floor: " << floor(intpart) << std::endl;
		std::cout << "number is a float number" << std::endl;
		isFloat = true;
	}
	else
	{
		std::cout << "ceil: " << ceil(floatNbr) << std::endl;
		std::cout << "floor: " << floor(intpart) << std::endl;
		std::cout << "number is not a float number" << std::endl;
	}
}
