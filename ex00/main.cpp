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
		const std::string inputArgv= argv[1];
		std::cout << "string inputArgv : " << inputArgv << std::endl;
		ScalarConverter::convert(inputArgv);
		return 0;
	}
	return (-1);
}
