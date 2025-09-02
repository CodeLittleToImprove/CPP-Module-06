#pragma once

# include <iostream>
# include <cstdlib>
# include "A.hpp"

class Base
{
	private:
		// Base();
		// Base(const Base &other);
		// Base& operator=(const Base& other);
	public:
		virtual ~Base();
		Base* generate(void);
};
