/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:11:14 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/09/08 15:47:25 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <math.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

int main()
{
	std::cout << CYAN;
	std::cout << "======================================" << std::endl;
	std::cout << "   ex02            " << std::endl;
	std::cout << "   Identify via pointer & reference   " << std::endl;
	std::cout << "======================================" << std::endl;
	std::cout << RESET << std::endl;

	//random test
	std::cout << YELLOW << "\n[ Random test like subject requirement ]" << RESET << std::endl;
	srand(static_cast<unsigned int>(time(NULL)));
	Base *base;
	base = generate(); //base points now to an object A or B or C
	identify(base); // here I can throw base directly because its expecting a pointer
	// identify(*base); // here I have to deference it and throw the object itself in

	// or the long way to put in as a reference
	Base &ref = *base;
	identify(ref);
	delete base;

	//run random test 10 times
	std::cout << YELLOW << "\n[ Random test loop ]" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
	}

	//put null into identify
	std::cout << YELLOW << "\n[ NULL pointer test ]" << RESET << std::endl;
	identify(NULL);

	// check every derived class
	std::cout << YELLOW << "\n[ Explicit class tests ]" << RESET << std::endl;
	A a;
	B b;
	C c;

	identify(&a);
	identify(a);

	identify(&b);
	identify(b);

	identify(&c);
	identify(c);

	return 0;
}