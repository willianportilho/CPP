/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:49:12 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/15 20:02:59 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
	std::cout << "copy ScalarConverter constructor called" << std::endl;
	return ;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "destructor ScalarConverter called" << std::endl;
	return ;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &rhs)
{
	if (this != &rhs)
	{
		;
	}
	std::cout << "assignment copy ScalarConverter called" << std::endl;
	return (*this);
}
