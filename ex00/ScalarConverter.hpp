#pragma once

# include <iostream>
# include <string>
# include <cstdlib>
# include <math.h>
# include <limits>

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
