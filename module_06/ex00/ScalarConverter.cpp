/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:49:12 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/17 23:01:34 by wportilh         ###   ########.fr       */
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
	return ;
}

ScalarConverter::~ScalarConverter(void)
{
	return ;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &rhs)
{
	if (this != &rhs)
	{
		this->_setType(rhs._getType());
		this->_cast_char = rhs._cast_char;
		this->_cast_int = rhs._cast_int;
		this->_cast_float = rhs._cast_float;
		this->_cast_double = rhs._cast_double;
	}
	return (*this);
}


void	ScalarConverter::_detectEmpty(std::string const arg)
{
	if (!arg.length())
		_setType(_IS_INVALID);
	return ;	
}

void	ScalarConverter::_detectSpecialCases(std::string const arg)
{
	if ((arg == "-inff") | (arg == "+inff") | (arg == "nanf"))
		_setType(_IS_SPECIAL_FLOAT);
	else if ((arg == "-inf") | (arg == "+inf") | (arg == "nan"))
		_setType(_IS_SPECIAL_DOUBLE);
	return ;
}

void	ScalarConverter::_detectChar(std::string const arg)
{
	if (_getType() != _UNDEFINED_TYPE)
		return ;
	if (arg.length() == 1)
	{
		if (std::isdigit(arg[0]) == false)
			_setType(_IS_CHAR);
	}
	return ;
}

void	ScalarConverter::_detectInt(std::string const arg)
{
	if (_getType() != _UNDEFINED_TYPE)
		return ;

	for (int i = 0; arg[i]; i++)
	{
		if ((std::isdigit(arg[i]) == false) && (i > 0))
			return ;
	}
	if (std::isdigit(arg[0]) == false && arg[0] != '-')
		return ;
	_setType(_IS_INT);
	return ;
}

void	ScalarConverter::_detectFloatOrDouble(std::string const arg)
{
	if (_getType() != _UNDEFINED_TYPE)
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
			_setType(_IS_INVALID);
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
		_setType(_IS_INVALID);
		return ;
	}
	if (amount_f == 1)
		_setType(_IS_FLOAT);
	else
		_setType(_IS_DOUBLE);
	return ;
}

void	ScalarConverter::_detectType(std::string const arg)
{
	_detectEmpty(arg);
	_detectSpecialCases(arg);
	_detectChar(arg);
	_detectInt(arg);
	_detectFloatOrDouble(arg);
	return ;
}

void	ScalarConverter::_handleInvalid(void)
{
	std::cout << "char: impossible"		<< std::endl;
	std::cout << "int: impossible"		<< std::endl;
	std::cout << "float: impossible"	<< std::endl;
	std::cout << "double: impossible"	<< std::endl;
	return ;
}

void	ScalarConverter::_handleSpecialFloat(std::string const arg)
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

void	ScalarConverter::_handleSpecialDouble(std::string const arg)
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

void	ScalarConverter::_handleChar(std::string const arg)
{
	_cast_char = arg[0];
	_cast_int = static_cast<int>(_cast_char);
	_cast_float = static_cast<float>(_cast_char);
	_cast_double = static_cast<double>(_cast_char);

	std::cout << "char: ";
	if (std::isprint(_cast_char) != false)
		std::cout << "'" << _cast_char	<< "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: " << _cast_int << std::endl;

	std::cout << "float: "	<< _cast_float << ".0f" << std::endl;

	std::cout << "double: "	<< _cast_double << ".0" << std::endl;
	return ;
}

void	ScalarConverter::_handleInt(std::string const arg)
{
	long int	num = strtol(arg.c_str(), NULL, 10);
	if ((num > std::numeric_limits<int>::max())
	|| (num < std::numeric_limits<int>::min()))
	{
		_handleInvalid();
		return ;
	}
	
	_cast_int = num;
	_cast_char = static_cast<char>(_cast_int);
	_cast_float = static_cast<float>(_cast_int);
	_cast_double = static_cast<double>(_cast_int);

	std::cout << "char: ";
	if (_cast_int < 0 || _cast_int > 127)
		std::cout << "impossible" << std::endl;
	else if (std::isprint(_cast_char) != false)
		std::cout << "'" << _cast_char << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: " << _cast_int << std::endl;

	std::cout << "float: "
	<< std::fixed << std::setprecision(1)
	<< _cast_float << "f" << std::endl;

	std::cout << "double: "	<< _cast_double << std::endl;

	std::cout.unsetf(std::ios::floatfield);

	return ;
}

void	ScalarConverter::_handleFloat(std::string const arg)
{
	_cast_float = atof(arg.c_str());
	
	int precision = 1;
	size_t pos = arg.find('.');
	if (pos != std::string::npos)
	{
		precision--;
		while (arg[++pos] && arg[pos] != 'f')
			precision++;
	}

	_cast_int = static_cast<int>(_cast_float);
	_cast_char = static_cast<char>(_cast_float);
	_cast_double = static_cast<double>(_cast_float);

	std::cout << "char: ";
	if (_cast_double <= -1.0f || _cast_double >= 128.0f)
		std::cout << "impossible" << std::endl;
	else if (std::isprint(_cast_char) != false)
		std::cout << "'" << _cast_char << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: ";
	if (_cast_float > std::numeric_limits<int>::max()
	|| _cast_float < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << _cast_int << std::endl;

	std::cout << "float: "
	<< std::fixed << std::setprecision(precision)
	<< _cast_float << "f" << std::endl;

	std::cout << "double: "	<< _cast_double << std::endl;

	std::cout.unsetf(std::ios::floatfield);

	return ;
}

void	ScalarConverter::_handleDouble(std::string const arg)
{
	_cast_double = strtod(arg.c_str(), NULL);
	
	int precision = 1;
	size_t pos = arg.find('.');
	if (pos != std::string::npos)
	{
		precision--;
		while (arg[++pos])
			precision++;
	}

	_cast_int = static_cast<int>(_cast_double);
	_cast_char = static_cast<char>(_cast_double);
	_cast_float = static_cast<float>(_cast_double);

	std::cout << "char: ";
	if (_cast_double <= -1.0 || _cast_double >= 128.0)
		std::cout << "impossible" << std::endl;
	else if (std::isprint(_cast_char) != false)
		std::cout << "'" << _cast_char << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: ";
	if (_cast_double > std::numeric_limits<int>::max()
	|| _cast_double < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << _cast_int << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(precision)
	<< _cast_float << "f" << std::endl;

	std::cout << "double: "	<< _cast_double << std::endl;

	std::cout.unsetf(std::ios::floatfield);
	return ;
}

void	ScalarConverter::convert(std::string const arg)
{
	_detectType(arg);
	switch (_getType())
	{
		case _IS_INVALID:
			_handleInvalid(); break;
		case _IS_SPECIAL_FLOAT:
			_handleSpecialFloat(arg); break;
		case _IS_SPECIAL_DOUBLE:
			_handleSpecialDouble(arg); break;
		case _IS_CHAR:
			_handleChar(arg); break;
		case _IS_INT:
			_handleInt(arg); break;
		case _IS_FLOAT:
			_handleFloat(arg); break;
		case _IS_DOUBLE:
			_handleDouble(arg); break;
		default:
			std::cout << "convert: error: invalid argument" << std::endl; break;
	}
	return ;
}

int	ScalarConverter::_getType(void)
{
	return (_type);
}

void	ScalarConverter::_setType(int const type)
{
	_type = type;
	return ;
}

int		ScalarConverter::_type = -1;
char	ScalarConverter::_cast_char = '0';
int		ScalarConverter::_cast_int = 0;
float	ScalarConverter::_cast_float = 0;
double	ScalarConverter::_cast_double = 0;
