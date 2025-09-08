/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:06:22 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/09/08 16:06:23 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
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
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr) ;
		static Data* deserialize(uintptr_t raw) ;
};
