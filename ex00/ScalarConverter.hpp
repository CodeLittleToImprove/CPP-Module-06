/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:10:18 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/09/08 16:10:19 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <limits>
# include <cstdlib>  // for strtol, strtod, strtof
# include <iomanip> // needed for setprecision

enum LiteralType {
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_PSEUDO_FLOAT,
	TYPE_PSEUDO_DOUBLE,
	TYPE_INVALID
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter& operator=(const ScalarConverter& other);
	public:
		~ScalarConverter();
		static void convert(const std::string& input) ;
};

//converters.cpp
char convertToChar(const std::string &input);
int convertToInt(const std::string &input, bool &valid_range);
double convertToDouble(const std::string &input, bool &valid_range);
float convertToFloat(const std::string &input, bool &valid_range);
float getPseudoFloat(const std::string &input);
double getPseudoDouble(const std::string &input);

//printers.cpp
void printFromChar(char c);
void printFromInt(int n, bool &valid_range);
void printFromFloat(float f, bool &valid_range);
void printFromDouble(double d, bool &valid_range);
void printFromPseudoFloat(float f);
void printFromPseudoDouble(double d);