
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
			std::cout << str[i] << " is not all alphabetic\n";
			return false;
		}
	}
	return true;
}

bool isPseudoLiteral(const std::string& input)
{
	if (input == "nan" || input == "+inf" || input == "-inf" ||
	input == "nanf" || input == "+inff" || input == "-inff")
	{
		return true;
	}
	return false;
}

bool isNumericLiteral(const std::string& str)
{
	bool hasDecimalPoint = false;
	bool hasDigits = false;
	std::size_t i = 0;

	if (str.empty())
		return false;
	if (str[i] == '+' || str[i] == '-')
		i++;
	for (; i < str.size(); ++i)
	{
		char c = str[i];
		if (isdigit(c))
			hasDigits = true;
		else if (c == '.' && !hasDecimalPoint)
			hasDecimalPoint = true;
		else if ((c == 'f' || c == 'F') && i == str.size() - 1)
			return hasDigits;
		else
			return false;
	}
	return hasDigits;
}
bool isFloatNotation(const std::string& str)
{
	if (str.empty())
		return false;
	if (str[str.size() - 1] == 'f' || str[str.size() - 1] == 'F')
	{
		std::cout << "contains a float notation" << std::endl;
		return true;
	}

	return false;
}

void ScalarConverter::convert(const std::string& input)
{
	bool isChar = false;
	bool isInt = false;
	bool isFloat = false;
	bool isDouble = false;
	bool needNbrConvert = true;
	bool isAllLetters = false;


	if (isAllAlphabetic(input))
	{
		isAllLetters = true;
		std::cout << "is all alphabetic" << std::endl;
	}
	if (isAllLetters && input.size() == 1)
	{
		char c = input[0];
		std::cout << "single char: " << c << std::endl;
		isChar = true;
		return ;
	}
	if (isPseudoLiteral(input))
	{
		needNbrConvert = false;
		std::cout << "no need for nbr conversion" << std::endl;
	}

	if (isNumericLiteral(input))
	{
		std::cout << "need for nbr conversion" << std::endl;
		if (isFloatNotation(input))
			isFloat = true;

		// char* notNumeric;
		long double tempNbr = strtod(input.c_str(), NULL); // string to double
		std::cout << "tempNbr " << tempNbr << std::endl;
		// if (*notNumeric != '\0')
		// {
		// 	std::cout << "not strict numeric: " << notNumeric << std::endl;
		// }
		double intpart;
		modf(tempNbr, &intpart); // split double into integral and fraction parts
		// std::cout << "fractpart: " << fractpart << std::endl;
		std::cout << "tempNbr: " << tempNbr << std::endl;
		std::cout << "intpart: " << intpart << std::endl;
		if (tempNbr != intpart)
		{
			// std::cout << "ceil: " << ceil(floatNbr) << std::endl;
			// std::cout << "floor: " << floor(intpart) << std::endl;
			std::cout << "number is a decimal number" << std::endl;
			if (isFloat)
			{
				float floatNbr = tempNbr;
				std::cout << "floatNbr: " << floatNbr << std::endl;
			}
			else
			{
				double doubleNbr = tempNbr;
				std::cout << "doubleNbr: " << doubleNbr << std::endl;
				isDouble = true;
			}
		}
		else
		{
			// std::cout << "ceil: " << ceil(floatNbr) << std::endl;
			// std::cout << "floor: " << floor(intpart) << std::endl;
			std::cout << "number is not a decimal number" << std::endl;
			if (intpart >= std::numeric_limits<int>::min() &&
			intpart <= std::numeric_limits<int>::max() &&
			std::floor(intpart) == intpart) // no fraction
			{
				int intNbr = static_cast<int>(intpart);
				std::cout << "intNbr: " << intNbr << std::endl;
				isInt = true;
			}
			else {
				std::cout << "cannot convert safely to int" << std::endl;
			}


		}


		if (isChar == true)
		{
			std::cout << "no need for nbr conversion" << std::endl;
			return;
		}
		// char* notNumeric;
		// // std::cout << "pre strtod: " << notNumeric << std::endl;
		// long double floatNbr = strtod(input.c_str(), &notNumeric); // string to double
		// if (*notNumeric != '\0')
		// {
		// 	std::cout << "not strict numeric: " << notNumeric << std::endl;
		// }
		// double intpart;
		// int intNbr = modf(floatNbr, &intpart);
		// std::cout << "floatNbr: " << floatNbr << std::endl;
		// std::cout << "intpart: " << intpart << std::endl;
		// if (floatNbr != intpart)
		// {
		// 	// std::cout << "ceil: " << ceil(floatNbr) << std::endl;
		// 	// std::cout << "floor: " << floor(intpart) << std::endl;
		// 	std::cout << "number is a float number" << std::endl;
		// 	isFloat = true;
		// }
		// else
		// {
		// 	// std::cout << "ceil: " << ceil(floatNbr) << std::endl;
		// 	// std::cout << "floor: " << floor(intpart) << std::endl;
		// 	std::cout << "number is not a float number" << std::endl;
		// }
	}
}
