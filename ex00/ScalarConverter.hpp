#pragma once

# include <iostream>
# include <cstdlib>

class ScalarConverter
{
	private:

	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
};
