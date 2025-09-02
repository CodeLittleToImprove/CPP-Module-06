#pragma once

# include <iostream>
# include <cstdlib>

#include "Base.hpp"

class A : public Base
{
	private:

	public:
		~A();
		Base* generate(void);
};
