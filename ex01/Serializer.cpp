/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:09:14 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/09/08 16:09:15 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Default constructor
Serializer::Serializer()
{
	// std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Serializer::Serializer(const Serializer &other)
{
	(void) other;
	// std::cout << "Copy constructor called" << std::endl;
}

// Copy Assignment operator overload
Serializer &Serializer::operator=(const Serializer &other)
{
	(void) other;
	// std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

// Destructor
Serializer::~Serializer(void)
{
	// std::cout << "Destructor called" << std::endl;
}

// uintptr_t is the “safe” integer type big enough to hold any pointer
uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return raw;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* ptr = reinterpret_cast<Data*>(raw);
	return ptr;
}


