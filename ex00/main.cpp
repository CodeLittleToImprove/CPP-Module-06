/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:11:14 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/09/08 16:09:57 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		const std::string inputArgv= argv[1];
		// std::cout << "string inputArgv : " << inputArgv << std::endl;
		ScalarConverter::convert(inputArgv);
		return 0;
	}
		std::cout << "At least one argument needed" << std::endl;
	return (-1);
}
