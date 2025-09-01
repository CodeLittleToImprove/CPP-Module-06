#pragma once

# include <iostream>
# include <string>
# include <cstdlib>
# include <math.h>
# include <limits>
# include <stdint.h>

struct Data{
	std::string value;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &other);
		Serializer& operator=(const Serializer& other);
	public:
		~Serializer();
		static uintptr_t serialize(Data* ptr) ;
		static Data* deserialize(uintptr_t raw) ;
};
