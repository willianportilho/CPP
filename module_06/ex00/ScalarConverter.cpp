/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:49:12 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/17 20:07:42 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) : _type(UNDEFINED_TYPE)
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


void	ScalarConverter::detectEmpty(std::string const arg)
{
	if (!arg.length())
			this->setType(IS_INVALID);
	return ;	
}

void	ScalarConverter::detectSpecialCases(std::string const arg)
{
	if ((arg == "-inff") | (arg == "+inff") | (arg == "nanf"))
		this->setType(IS_SPECIAL_FLOAT);
	else if ((arg == "-inf") | (arg == "+inf") | (arg == "nan"))
		this->setType(IS_SPECIAL_DOUBLE);
	return ;
}

void	ScalarConverter::detectChar(std::string const arg)
{
	if (this->getType() != UNDEFINED_TYPE)
		return ;
	if (arg.length() == 1)
	{
		if (std::isdigit(arg[0]) == false)
			this->setType(IS_CHAR);
	}
	return ;
}

void	ScalarConverter::detectInt(std::string const arg)
{
	if (this->getType() != UNDEFINED_TYPE)
		return ;

	for (int i = 0; arg[i]; i++)
	{
		if ((std::isdigit(arg[i]) == false) && (i > 0))
			return ;
	}
	if (std::isdigit(arg[0]) == false && arg[0] != '-')
		return ;
	this->setType(IS_INT);
	return ;
}

void	ScalarConverter::detectFloatOrDouble(std::string const arg)
{
	if (this->getType() != UNDEFINED_TYPE)
		return ;

	int	amount_f = 0, amount_dot = 0, amount_signal = 0;
	for (int i = 0; arg[i]; i++)
	{
		if (arg[i] == 'f')
			amount_f++;
		else if (arg[i] == '.')
			amount_dot++;
		else if (arg[i] == '-')
			amount_signal++;
		else if (std::isdigit(arg[i]) == false)
		{
			this->setType(IS_INVALID);
			return ;
		}
	}
	int pos = 0;
	if (amount_dot > 0)
		pos = arg.find(".");
	if (amount_f > 1 || (amount_f > 0 && arg[arg.length() - 1] != 'f')
	|| amount_dot > 1 || (amount_dot > 0 && arg[0] == '.')
	|| arg[pos + 1] == 'f' || arg[pos + 1] == '\0'
	|| amount_signal > 1 || (amount_signal > 0 && arg[0] != '-'))
	{
		this->setType(IS_INVALID);
		return ;
	}
	if (amount_f == 1)
		this->setType(IS_FLOAT);
	else
		this->setType(IS_DOUBLE);
	return ;
}

void	ScalarConverter::detectType(std::string const arg)
{
	detectEmpty(arg);
	detectSpecialCases(arg);
	detectChar(arg);
	detectInt(arg);
	detectFloatOrDouble(arg);
	return ;
}

void	ScalarConverter::handleInvalid(void)
{
	std::cout << "char: impossible"		<< std::endl;
	std::cout << "int: impossible"		<< std::endl;
	std::cout << "float: impossible"	<< std::endl;
	std::cout << "double: impossible"	<< std::endl;
	return ;
}

void	ScalarConverter::handleSpecialFloat(std::string const arg)
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

void	ScalarConverter::handleSpecialDouble(std::string const arg)
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

void	ScalarConverter::handleChar(std::string const arg)
{
	this->cast_char = arg[0];
	this->cast_int = static_cast<int>(this->cast_char);
	this->cast_float = static_cast<float>(this->cast_char);
	this->cast_double = static_cast<double>(this->cast_char);

	std::cout << "char: ";
	if (std::isprint(this->cast_char) != false)
		std::cout << "'" << this->cast_char	<< "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: " << this->cast_int	<< std::endl;

	std::cout << "float: "	<< this->cast_float << ".0f" << std::endl;

	std::cout << "double: "	<< this->cast_double << ".0" << std::endl;
	return ;
}

void	ScalarConverter::handleInt(std::string const arg)
{
	long int	num = strtol(arg.c_str(), NULL, 10);
	if ((num > std::numeric_limits<int>::max())
	|| (num < std::numeric_limits<int>::min()))
		handleInvalid();;
	
	this->cast_int = num;
	this->cast_char = static_cast<char>(this->cast_int);
	this->cast_float = static_cast<float>(this->cast_int);
	this->cast_double = static_cast<double>(this->cast_int);

	std::cout << "char: ";
	if (this->cast_int < 0 || this->cast_int > 127)
		std::cout << "impossible" << std::endl;
	else if (std::isprint(this->cast_char) != false)
		std::cout << "'" << this->cast_char << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: " << this->cast_int << std::endl;

	std::cout << "float: "
	<< std::fixed << std::setprecision(1)
	<< this->cast_float << "f" << std::endl;

	std::cout << "double: "	<< this->cast_double << std::endl;

	std::cout.unsetf(std::ios::floatfield);

	return ;
}

void	ScalarConverter::handleFloat(std::string const arg)
{
	this->cast_float = atof(arg.c_str());
	
	int precision = 1;
	size_t pos = arg.find('.');
	if (pos != std::string::npos)
	{
		precision--;
		while (arg[++pos] && arg[pos] != 'f')
			precision++;
	}

	this->cast_int = static_cast<int>(this->cast_float);
	this->cast_char = static_cast<char>(this->cast_float);
	this->cast_double = static_cast<double>(this->cast_float);

	std::cout << "char: ";
	if (this->cast_double <= -1.0f || this->cast_double >= 128.0f)
		std::cout << "impossible" << std::endl;
	else if (std::isprint(this->cast_char) != false)
		std::cout << "'" << this->cast_char << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: ";
	if (this->cast_float > std::numeric_limits<int>::max()
	|| this->cast_float < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << this->cast_int << std::endl;

	std::cout << "float: "
	<< std::fixed << std::setprecision(precision)
	<< this->cast_float << "f" << std::endl;

	std::cout << "double: "	<< this->cast_double << std::endl;

	std::cout.unsetf(std::ios::floatfield);

	return ;
}

void	ScalarConverter::handleDouble(std::string const arg)
{
	this->cast_double = strtod(arg.c_str(), NULL);
	
	int precision = 1;
	size_t pos = arg.find('.');
	if (pos != std::string::npos)
	{
		precision--;
		while (arg[++pos])
			precision++;
	}

	this->cast_int = static_cast<int>(this->cast_double);
	this->cast_char = static_cast<char>(this->cast_double);
	this->cast_float = static_cast<float>(this->cast_double);

	std::cout << "char: ";
	if (this->cast_double <= -1.0 || this->cast_double >= 128.0)
		std::cout << "impossible" << std::endl;
	else if (std::isprint(this->cast_char) != false)
		std::cout << "'" << this->cast_char << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: ";
	if (this->cast_double > std::numeric_limits<int>::max()
	|| this->cast_double < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << this->cast_int << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(precision)
	<< this->cast_float << "f" << std::endl;

	std::cout << "double: "	<< this->cast_double << std::endl;

	std::cout.unsetf(std::ios::floatfield);
	return ;
}

void	ScalarConverter::convert(std::string const arg)
{
	switch (this->getType())
	{
		case 0:
			handleInvalid(); break;
		case 1:
			handleSpecialFloat(arg); break;
		case 2:
			handleSpecialDouble(arg); break;
		case 3:
			handleChar(arg); break;
		case 4:
			handleInt(arg); break;
		case 5:
			handleFloat(arg); break;
		case 6:
			handleDouble(arg); break;
		default:
			std::cout << "default" << std::endl; break;
	}
	return ;
}

int	ScalarConverter::getType(void) const
{
	return (this->_type);
}

void	ScalarConverter::setType(int const type)
{
	this->_type = type;
	return ;
}
