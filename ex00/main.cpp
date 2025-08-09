/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:11:14 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/04/24 17:44:30 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <cmath>
#include <math.h>

#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		std::cout << "argv[1] : "<<argv[1] << std::endl;
		// if (is_int(argv[1])) {
		// 	std::cout << "argv[i]" "is int" << std::endl;
		// } else if (is_float(argv[1])) {
		// 	std::cout << "argv[i]" "is float" << std::endl;
		// } else {
		// 	std::cout << "argv[i]" "is unknown" << std::endl;
		// }
		// try to use strtol
		const std::string inputArgv= argv[1];
		std::cout << "inputArgv : " << inputArgv << std::endl;
		ScalarConverter::convert(inputArgv);
		// bool isFloat = false;
		// bool isChar = false;
		// char* end;
		// long double floatNumber = strtod(argv[1], &end);
		// double intpart;
		// // modf(floatNumber, &intpart);
		// // std::cout << "intpart: " << intpart << std::endl;
		// std::cout << "end: " << end << std::endl;
		// std::cout << "double: " << floatNumber << std::endl;
		// if (ceil(floatNumber) != floor(intpart))
		// {
		// 	std::cout << "ceil: " << ceil(floatNumber) << std::endl;
		// 	std::cout << "floor: " << floor(intpart) << std::endl;
		// 	std::cout << "number is a float number" << std::endl;
		// }
		// else
		// {
		// 	std::cout << "ceil: " << ceil(floatNumber) << std::endl;
		// 	std::cout << "floor: " << floor(intpart) << std::endl;
		// 	std::cout << "number is not a float number" << std::endl;
		// }
		//
		//
		// long int integerNumber = strtol(argv[1], &end, 10);
		// std::cout << "end: " << end << std::endl;
		// std::cout <<  "int: " << integerNumber << std::endl;
		//
		// if (integerNumber == 0)
		// {
		// 	char c = argv[1][0];
		// 	if (isalpha(c))
		// 		isChar = true;
		// 	std::cout << "char: " << c << std::endl;
		// }
		// return (0);
	}
	return (-1);
}
