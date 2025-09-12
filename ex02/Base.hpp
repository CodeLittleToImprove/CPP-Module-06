
#pragma once

# include <iostream>
# include <cstdlib>

class Base
{
	public:
		virtual~Base(); // need to be virtual to be polymorphic otherwise dynamic cast would not

};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);
