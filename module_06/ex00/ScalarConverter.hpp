/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/17 21:46:21 by wportilh         ###   ########.fr       */
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
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter(void);
		ScalarConverter	&operator=(ScalarConverter const &rhs);
	
		void	detectType(std::string const arg);
		void	convert(std::string const arg);
	private:
		unsigned int	_type;
		char			_cast_char;
		int				_cast_int;
		float			_cast_float;
		double			_cast_double;

		void	_detectEmpty(std::string const arg);
		void	_detectSpecialCases(std::string const arg);
		void	_detectChar(std::string const arg);
		void	_detectInt(std::string const arg);
		void	_detectFloatOrDouble(std::string const arg);

		void	_handleInvalid(void);
		void	_handleSpecialFloat(std::string const arg);
		void	_handleSpecialDouble(std::string const arg);
		void	_handleChar(std::string const arg);
		void	_handleInt(std::string const arg);
		void	_handleFloat(std::string const arg);
		void	_handleDouble(std::string const arg);

		int		_getType(void) const;
		void	_setType(int const type);
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
