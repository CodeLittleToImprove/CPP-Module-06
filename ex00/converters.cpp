/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:01:17 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/09/08 17:01:21 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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
		// std::cout << "overflow double or underflow double" << std::endl;
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
		// std::cout << "overflow float or underflow float" << std::endl;
		return 0.0f;
	}

	valid_range = true;
	// std::cout << "float conversion successful " << std::endl; // not reaching here
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