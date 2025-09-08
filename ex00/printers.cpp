/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:01:25 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/09/08 17:01:28 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void printFromChar(char c)
{
	if (!isprint(static_cast<unsigned char>(c)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;

	int n = static_cast<int>(c); // no cast needed but i like it this way
	std::cout << "int: " << n << std::endl;

	float f = static_cast<float>(c);
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

	double d = static_cast<double>(c);
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void printFromInt(int n, bool& valid_range)
{
	if (n < 0 || n > 127 || (n == 0 && valid_range == false))
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(n)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	if (valid_range == true)
	{
		std::cout << "int: " << n << std::endl;
		float f = static_cast<float>(n);
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		double d = static_cast<double>(n);
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}
	else if (valid_range == false)
	{
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

void printFromFloat(float f, bool& valid_range)
{
	if (f < 0 || f > 127 || (f == 0 && valid_range == false))
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(f)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	if (valid_range == true)
	{
		if (f >= static_cast<float>(std::numeric_limits<int>::min()) &&
			f <= static_cast<float>(std::numeric_limits<int>::max()))
			std::cout << "int: " << static_cast<int>(f) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		double d = static_cast<double>(f);
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}
	else if (valid_range == false)
	{
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

void printFromDouble(double d, bool& valid_range)
{
	if (d < 0 || d > 127 || (d == 0 && valid_range == false))
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(d)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	if (valid_range == true)
	{
		if (d >= static_cast<double>(std::numeric_limits<int>::min()) &&
			d <= static_cast<double>(std::numeric_limits<int>::max()))
			std::cout << "int: " << static_cast<int>(d) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		float f = static_cast<float>(d);
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
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
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	double d = static_cast<double>(f);
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void printFromPseudoDouble(double d)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	double f = static_cast<float>(d);
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
