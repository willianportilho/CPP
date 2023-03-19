/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/17 22:50:55 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_H
# define SCALARCONVERT_H

#include <iostream>
#include <string>
#include <cctype>
#include <stdlib.h>
#include <limits>
#include <iomanip>

class	ScalarConverter
{
	public:
		~ScalarConverter(void);
	
		static void	convert(std::string const arg);
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter	&operator=(ScalarConverter const &rhs);

		static int			_type;
		static char			_cast_char;
		static int			_cast_int;
		static float		_cast_float;
		static double		_cast_double;

		static void	_detectType(std::string const arg);
		static void	_detectEmpty(std::string const arg);
		static void	_detectSpecialCases(std::string const arg);
		static void	_detectChar(std::string const arg);
		static void	_detectInt(std::string const arg);
		static void	_detectFloatOrDouble(std::string const arg);

		static void	_handleInvalid(void);
		static void	_handleSpecialFloat(std::string const arg);
		static void	_handleSpecialDouble(std::string const arg);
		static void	_handleChar(std::string const arg);
		static void	_handleInt(std::string const arg);
		static void	_handleFloat(std::string const arg);
		static void	_handleDouble(std::string const arg);

		static int	_getType(void);
		static void	_setType(int const type);
		enum e_type
		{
			_UNDEFINED_TYPE = -1,
			_IS_INVALID,
    		_IS_SPECIAL_FLOAT,
			_IS_SPECIAL_DOUBLE,
			_IS_CHAR,
			_IS_INT,
			_IS_FLOAT,
			_IS_DOUBLE
		};
};

#endif
