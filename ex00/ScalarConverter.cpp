/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:10:06 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/09/08 16:10:07 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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
		// std::cout << "found TYPE_PSEUDO_DOUBLE" << std::endl;
		return TYPE_PSEUDO_DOUBLE;
	}
	if (input == "nanf" || input == "+inff" || input == "-inff")
	{
		// std::cout << "found TYPE_PSEUDO_FLOAT" << std::endl;
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
		// need to check the new condition if this not break anything?
		else if (c == '.' && !hasDecimalPoint && str[0] != '.' && str[str.size() - 1] != '.')
		{
			hasDecimalPoint = true;
		}
		else if ((c == 'f' || c == 'F') && i == str.size() - 1 && str[str.size() - 2] != '.')
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
		// std::cout << "found TYPE_CHAR" << std::endl;
		return TYPE_CHAR;
	}

	LiteralType num = detectNumericalLiteral(input);
	if (num != TYPE_INVALID)
	{
		// std::cout << "num: " << literalTypeToString(num) << std::endl;
		return num;
	}
	return TYPE_INVALID;
}

void ScalarConverter::convert(const std::string &input)
{
	bool valid_range = false;
	LiteralType type = detectType(input);
	// std::cout << "type: " << literalTypeToString(type) << std::endl;
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
			printFromInt(i, valid_range);
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
			std::cout << "Invalid input, Conversation not possible!" << std::endl;
	}
}
