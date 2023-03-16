/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/16 12:52:20 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_H
# define SCALARCONVERT_H

#include <iostream>
#include <string>

class	ScalarConverter
{
	public:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter(void);
		ScalarConverter	&operator=(ScalarConverter const &rhs);
		void			detect_type(std::string const arg);
		void			handleExtremeFloat(std::string const arg);
		void			handleExtremeDouble(std::string const arg);
		void			convert(std::string const arg);
		unsigned int	getType(void) const;
		void			setType(unsigned int const type);
	private:
		unsigned int		_type;
		enum e_type
		{
    		IS_EXTREME_FLOAT,
			IS_EXTREME_DOUBLE,
			IS_CHAR,
			IS_INT,
			IS_FLOAT,
			IS_DOUBLE,
			IS_INVALID
		};
};

#endif
