/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:11:14 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/09/08 16:05:43 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <math.h>
#include "Serializer.hpp"

int main()
{
	Data d;
	d.value = "cats are cute";

	std::cout << "Original Data object address: " << &d << std::endl;

	// Serialize pointer → integer
	uintptr_t raw = Serializer::serialize(&d);
	std::cout << "Serialized (uintptr_t): " << raw << std::endl;

	// Deserialize integer → pointer
	Data* restored = Serializer::deserialize(raw);
	std::cout << "Restored Data object address: " << restored << std::endl;

	if (restored == &d)
		std::cout << "Pointer restored correctly" << std::endl;
	else
		std::cout << "Pointer restore failed" << std::endl;

	std::cout << "Restored Data contents:" << std::endl;
	std::cout << " value = " << restored->value << std::endl;
	std::cout << " direct access = " << d.value << std::endl;

	return 0;
}