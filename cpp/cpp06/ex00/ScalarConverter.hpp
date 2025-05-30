/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bposa <bposa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:53:42 by bposa             #+#    #+#             */
/*   Updated: 2025/04/14 19:37:26 by bposa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype> // isprint
#include <limits> 
#include <iomanip> //fixed

#define REDISH "\033[1;31m"
#define YELLOWISH "\033[33m"
#define GREENISH "\033[1;32m"
#define RESETISH "\033[0m"

class ScalarConverter {
	ScalarConverter()										= delete;
	ScalarConverter(const ScalarConverter& obj)				= delete;
	ScalarConverter &operator=(const ScalarConverter& obj)	= delete;
	~ScalarConverter()										= delete;
	
	public:
		static void convert(const std::string& literal);
};

#endif
