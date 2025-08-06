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


#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		std::cout << argv[1] << std::endl;
		// if (is_int(argv[1])) {
		// 	std::cout << "argv[i]" "is int" << std::endl;
		// } else if (is_float(argv[1])) {
		// 	std::cout << "argv[i]" "is float" << std::endl;
		// } else {
		// 	std::cout << "argv[i]" "is unknown" << std::endl;
		// }
		// try to use strtol
		int x = strtol(argv[1], NULL, 10);
		std::cout << x << std::endl;
		return (0);
	}
	return (-1);
}
