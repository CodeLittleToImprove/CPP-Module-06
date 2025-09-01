#include "ScalarConverter.hpp"

#include <algorithm>
#include <iomanip>

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

void printFromChar(char c)
{
	if (!isprint(static_cast<unsigned char>(c)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;

	int n = static_cast<int>(c); // no cast needed but i like it this way
	std::cout << "int: " << n << std::endl;

	float f = static_cast<float>(n);
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

	double d = static_cast<double>(n);
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void printFromInt(int n, bool &valid_range)
{
	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(n)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	if (valid_range == true)
	{
		std::cout << "int: "<< n << std::endl;
		float f = static_cast<float>(n);
		std::cout << "float: "<< std::fixed << std::setprecision(1) << f << "f" << std::endl;
		double d = static_cast<double>(n);
		std::cout << "double: "<< std::fixed << std::setprecision(1) << d << std::endl;
	}
	else if (valid_range == false)
	{
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

void printFromFloat(float f, bool &valid_range)
{
	if (f < 0 || f > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(f)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	if (valid_range == true)
	{
		std::cout << "int: "<< f << std::endl;
		std::cout << "float: "<< std::fixed << std::setprecision(1) << f << "f" << std::endl;
		double d = static_cast<double>(f);
		std::cout << "double: "<< std::fixed << std::setprecision(1) << d << std::endl;
	}
	else if (valid_range == false)
	{
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}
void printFromDouble(double d, bool &valid_range)
{
	if (d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(d)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	if (valid_range == true)
	{
		std::cout << "int: "<< d << std::endl;
		float f = static_cast<float>(d);
		std::cout << "float: "<< std::fixed << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double: "<< std::fixed << std::setprecision(1) << d << std::endl;
	}
	else if (valid_range == false)
	{
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

void printFromPseudoFloat(float f)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: "<< std::fixed << std::setprecision(1) << f << "f" << std::endl;
	double d = static_cast<double>(f);
	std::cout << "double: "<< std::fixed << std::setprecision(1) << d << std::endl;
}

void printFromPseudoDouble(double d)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	double f = static_cast<float>(d);
	std::cout << "float: "<< std::fixed << std::setprecision(1) << f << std::endl;
	std::cout << "double: "<< std::fixed << std::setprecision(1) << d << std::endl;
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
	{
		std::cout << "overflow double or underflow double" << std::endl;
		return 0.0;
	}

	valid_range = true;
	return val;
}

float convertToFloat(const std::string &input, bool &valid_range)
{
	char *endptr;
	float val = strtof(input.c_str(), &endptr);

	if (*endptr != '\0'&& *endptr != 'f' && *endptr != 'F')
		return 0.0f;

	if (val > std::numeric_limits<float>::max() || val < -std::numeric_limits<float>::max())
	{
		std::cout << "overflow float or underflow float" << std::endl;
		return 0.0f;
	}

	valid_range = true;
	std::cout << "float conversion successful " << std::endl; // not reaching here
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
		default:				return "TYPE_INVALID";
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
	bool valid_range = false;
	LiteralType type = detectType(input);
	std::cout << "type: " << literalTypeToString(type) << std::endl;
	switch (type)
	{
		case TYPE_CHAR:
		{
			char c = convertToChar(input);
			printFromChar(c);
			break;
		}
		case TYPE_INT:
		{
			int i = convertToInt(input, valid_range);
			printFromInt(i, valid_range); // need to when printing to check if valid int value
			break;
		}
		case TYPE_FLOAT:
		{
			float f = convertToFloat(input, valid_range);
			printFromFloat(f, valid_range);
			break;
		}
		case TYPE_DOUBLE:
		{
			double d = convertToDouble(input,valid_range);
			printFromDouble(d, valid_range);
			break;
		}
		case TYPE_PSEUDO_FLOAT:
		{
			float f = getPseudoFloat(input);
			printFromPseudoFloat(f);
			break;
		}
		case TYPE_PSEUDO_DOUBLE:
		{
			double d = getPseudoDouble(input);
				printFromPseudoDouble(d);
			break;
		}
		default:
			std::cout << "Invalid input" << std::endl;
	}
}
