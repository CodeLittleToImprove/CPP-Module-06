#pragma once

# include <iostream>
# include <cstdlib>
# include <math.h>
# include <limits>

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
