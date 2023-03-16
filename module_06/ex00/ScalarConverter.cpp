/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:49:12 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/16 12:59:22 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) : _type(0)
{
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
	//std::cout << "copy ScalarConverter constructor called" << std::endl;
	return ;
}

ScalarConverter::~ScalarConverter(void)
{
	//std::cout << "destructor ScalarConverter called" << std::endl;
	return ;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &rhs)
{
	if (this != &rhs)
		this->setType(rhs.getType());
	//std::cout << "assignment copy ScalarConverter called" << std::endl;
	return (*this);
}

void	ScalarConverter::detect_type(std::string const arg)
{
	if ((arg == "-inff") | (arg == "+inff") | (arg == "nanf"))
		this->setType(IS_EXTREME_FLOAT);
	else if ((arg == "-inf") | (arg == "+inf") | (arg == "nan"))
		this->setType(IS_EXTREME_DOUBLE);
	else
		this->setType(IS_INVALID);
	return ;
}

void	ScalarConverter::handleExtremeFloat(std::string const arg)
{
	std::string const type[3] = {"-inff", "+inff", "nanf"};

	for (int i = 0; i < 3; i++)
	{
		if (type[i] == arg)
		{
			std::string str = arg.substr(0, (arg.length() - 1));

			std::cout << "char: impossible"	<< std::endl;
			std::cout << "int: impossible"	<< std::endl;
			std::cout << "float: "	<< arg	<< std::endl;
			std::cout << "double: "	<< str	<< std::endl;
		}
	}
	return ;
}

void	ScalarConverter::handleExtremeDouble(std::string const arg)
{
	std::string const type[3] = {"-inf", "+inf", "nan"};

	for (int i = 0; i < 3; i++)
	{
		if (type[i] == arg)
		{
			std::string str = arg + "f";

			std::cout << "char: impossible"	<< std::endl;
			std::cout << "int: impossible"	<< std::endl;
			std::cout << "float: "	<< str	<< std::endl;
			std::cout << "double: "	<< arg	<< std::endl;
		}
	}
	return ;
}

void	ScalarConverter::convert(std::string const arg)
{
	switch (this->getType())
	{
		case 0:
			handleExtremeFloat(arg);
			break;
		case 1:
			handleExtremeDouble(arg);
			break;
	}
	return ;
}

unsigned int	ScalarConverter::getType(void) const
{
	return (this->_type);
}

void	ScalarConverter::setType(unsigned int const type)
{
	this->_type = type;
	return ;
}
