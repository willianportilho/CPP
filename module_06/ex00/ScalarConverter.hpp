/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/17 11:06:29 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_H
# define SCALARCONVERT_H

#include <iostream>
#include <string>
#include <cctype>

class	ScalarConverter
{
	public:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter(void);
		ScalarConverter	&operator=(ScalarConverter const &rhs);
	
		void	detectType(std::string const arg);
		void	detectEmpty(std::string const arg);
		void	detectSpecialCases(std::string const arg);
		void	detectChar(std::string const arg);
		void	detectInt(std::string const arg);
		void	detectFloatOrDouble(std::string const arg);

		void	handleInvalid(void);
		void	handleSpecialFloat(std::string const arg);
		void	handleSpecialDouble(std::string const arg);
		void	handleChar(std::string const arg);

		void	convert(std::string const arg);

		int		getType(void) const;
		void	setType(int const type);
	private:
		unsigned int		_type;

		enum e_type
		{
			UNDEFINED_TYPE = -1,
			IS_INVALID,
    		IS_SPECIAL_FLOAT,
			IS_SPECIAL_DOUBLE,
			IS_CHAR,
			IS_INT,
			IS_FLOAT,
			IS_DOUBLE
		};
};

#endif
