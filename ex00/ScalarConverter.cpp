#include "ScalarConverter.hpp"

#include <algorithm>

// Default constructor
ScalarConverter::ScalarConverter()
{
	// std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void) other;
	// std::cout << "Copy constructor called" << std::endl;
}

// Copy Assignment operator overload
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
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


char convertToChar(const std::string &input)
{
	char c = input[0];
	return c;
}

int convertToInt(const std::string &input, bool &valid_range)
{
	char *endptr;
	long val = strtol(input.c_str(), &endptr, 10);
	if (*endptr != '\0')
		return 0;
	if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
		return 0;
	valid_range = true;
	return static_cast<int>(val);
}

double convertToDouble(const std::string &input, bool &valid_range)
{
	char *endptr;
	double val = strtod(input.c_str(), &endptr);

	if (*endptr != '\0')
		return 0.0;

	if (val > std::numeric_limits<double>::max() || val < -std::numeric_limits<double>::max())
		return 0.0;

	valid_range = true;
	return val;
}

float convertToFloat(const std::string &input, bool &valid_range)
{
	char *endptr;
	float val = strtof(input.c_str(), &endptr);

	if (*endptr != '\0')
		return 0.0f;

	if (val > std::numeric_limits<float>::max() || val < -std::numeric_limits<float>::max())
		return 0.0f;

	valid_range = true;
	return val;
}

float getPseudoFloat(const std::string &input)
{
	if (input == "+inff")
		return std::numeric_limits<float>::infinity();
	if (input == "-inff")
		return -std::numeric_limits<float>::infinity();
	return std::numeric_limits<float>::quiet_NaN();
}

double getPseudoDouble(const std::string &input)
{
	if (input == "+inf")
		return std::numeric_limits<double>::infinity();
	if (input == "-inf")
		return -std::numeric_limits<double>::infinity();
	return std::numeric_limits<double>::quiet_NaN();
}

std::string literalTypeToString(LiteralType type) // only for  debug
{
	switch (type)
	{
		case TYPE_CHAR:         return "TYPE_CHAR";
		case TYPE_INT:          return "TYPE_INT";
		case TYPE_FLOAT:        return "TYPE_FLOAT";
		case TYPE_DOUBLE:       return "TYPE_DOUBLE";
		case TYPE_PSEUDO_FLOAT: return "TYPE_PSEUDO_FLOAT";
		case TYPE_PSEUDO_DOUBLE:return "TYPE_PSEUDO_DOUBLE";
		default:                                 return "TYPE_INVALID";
	}
}

LiteralType detectPseudo(const std::string &input)
{
	if (input == "nan" || input == "+inf" || input == "-inf")
	{
		std::cout << "found TYPE_PSEUDO_DOUBLE" << std::endl;
		return TYPE_PSEUDO_DOUBLE;
	}
	if (input == "nanf" || input == "+inff" || input == "-inff")
	{
		std::cout << "found TYPE_PSEUDO_FLOAT" << std::endl;
		return TYPE_PSEUDO_FLOAT;
	}
	return TYPE_INVALID;
}

LiteralType detectNumericalLiteral(const std::string &str)
{
	bool hasDecimalPoint = false;
	bool hasDigits = false;
	std::size_t i = 0;

	if (str.empty())
		return TYPE_INVALID;
	if (str[i] == '+' || str[i] == '-')
		i++;
	for (; i < str.size(); ++i)
	{
		char c = str[i];
		if (isdigit(c))
		{
			hasDigits = true;
		}
		else if (c == '.' && !hasDecimalPoint)
		{
			hasDecimalPoint = true;
		}
		else if ((c == 'f' || c == 'F') && i == str.size() - 1)
			return hasDigits ? TYPE_FLOAT : TYPE_INVALID;
		else
		{
			return TYPE_INVALID;
		}
	}
	if (!hasDigits)
		return TYPE_INVALID;
	if (hasDecimalPoint)
		return TYPE_DOUBLE;
	return TYPE_INT;
}

LiteralType detectType(const std::string &input)
{
	if (input.empty())
		return TYPE_INVALID;

	LiteralType pseudo = detectPseudo(input);
	if (pseudo != TYPE_INVALID)
		return pseudo;

	if (input.size() == 1 && isprint(input[0]) && !isdigit(input[0]))
	{
		std::cout << "found TYPE_CHAR" << std::endl;
		return TYPE_CHAR;
	}

	LiteralType num = detectNumericalLiteral(input);
	if (num != TYPE_INVALID)
	{
		std::cout << "num: " << literalTypeToString(num) << std::endl;
		return num;
	}
	return TYPE_INVALID;

}


void ScalarConverter::convert(const std::string &input)
{
	// enum LiteralType {
	// 	TYPE_CHAR,
	// 	TYPE_INT,
	// 	TYPE_FLOAT,
	// 	TYPE_PSEUDO_FLOAT,
	// 	TYPE_PSEUDO_DOUBLE,
	// };
	bool valid_range = false;
	LiteralType type = detectType(input);
	std::cout << "type: " << literalTypeToString(type) << std::endl;
	switch (type)
	{
		case TYPE_CHAR:
		{
			char c = convertToChar(input);
			break;
		}
		case TYPE_INT:
		{
			long int i = convertToInt(input, valid_range); // need to when printing to check if valid int value
			break;
		}
		case TYPE_FLOAT:
		{
			float f = convertToFloat(input, valid_range);
			break;
		}
		case TYPE_DOUBLE:
		{
			double d = convertToFloat(input,valid_range);
			break;
		}
		case TYPE_PSEUDO_FLOAT:
		{
			float f = getPseudoFloat(input);
			break;
		}
		case TYPE_PSEUDO_DOUBLE:
		{
			double d = getPseudoDouble(input);
			break;
		}
		default:
			std::cout << "Invalid input" << std::endl;
	}


	// if (isAllLetters && input.size() == 1)
	// {
	// 	char c = input[0];
	// 	std::cout << "single char: " << c << std::endl;
	// 	isChar = true;
	// 	return;
	// }
	// if (detectPseudo(input))
	// {
	// 	needNbrConvert = false;
	// 	std::cout << "no need for nbr conversion" << std::endl;
	// }
	//
	// if (isNumericLiteral(input) && needNbrConvert == true)
	// {
	// 	std::cout << "need for nbr conversion" << std::endl;
	// 	if (isFloatNotation(input))
	// 		isFloat = true;
	// 	long double tempNbr = strtod(input.c_str(), NULL); // string to double
	// 	std::cout << "tempNbr " << tempNbr << std::endl;
	// 	double intpart;
	// 	modf(tempNbr, &intpart); // split double into integral and fraction parts
	// 	std::cout << "tempNbr: " << tempNbr << std::endl;
	// 	std::cout << "intpart: " << intpart << std::endl; // int conversion does not work as intended
	// 	if (tempNbr != intpart)
	// 	{
	// 		// std::cout << "ceil: " << ceil(floatNbr) << std::endl;
	// 		// std::cout << "floor: " << floor(intpart) << std::endl;
	// 		std::cout << "number is a decimal number" << std::endl;
	// 		if (isFloat)
	// 		{
	// 			float floatNbr = tempNbr;
	// 			std::cout << "floatNbr: " << floatNbr << std::endl;
	// 		}
	// 		else
	// 		{
	// 			double doubleNbr = tempNbr;
	// 			std::cout << "doubleNbr: " << doubleNbr << std::endl;
	// 			isDouble = true;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		// std::cout << "ceil: " << ceil(floatNbr) << std::endl;
	// 		// std::cout << "floor: " << floor(intpart) << std::endl;
	// 		std::cout << "number is not a decimal number" << std::endl;
	// 		if (intpart >= std::numeric_limits<int>::min() &&
	// 		    intpart <= std::numeric_limits<int>::max() &&
	// 		    std::floor(intpart) == intpart) // no fraction
	// 		{
	// 			int intNbr = static_cast<int>(intpart);
	// 			std::cout << "intNbr: " << intNbr << std::endl;
	// 			isInt = true;
	// 		}
	// 		else
	// 		{
	// 			std::cout << "cannot convert safely to int" << std::endl;
	// 		}
	// 	}
	//
	// 	std::cout << "isChar bool:" << isChar << std::endl;
	// 	std::cout << "isInt bool:" << isInt << std::endl;
	// 	std::cout << "isFloat bool:" << isFloat << std::endl;
	// 	std::cout << "isDouble bool:" << isDouble << std::endl;
	// 	if (!isInt && !isFloat && !isDouble)
	// 	{
	// 		std::cout << "conversion not possible" << std::endl;
	// 	}
	// 	// if (isChar == true)
	// 	// {
	// 	// 	std::cout << "no need for nbr conversion" << std::endl;
	// 	// 	return;
	// 	// }
	// }
}
