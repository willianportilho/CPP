/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:58:14 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/07 16:56:36 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <ctime>
#include <stdlib.h>
#include <cctype>
#include "Exceptions.hpp"

class	BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange(void);
		BitcoinExchange	&operator=(BitcoinExchange const &rhs);
		void			exchange(std::string const fileName);
	private:
		void			get_time(void);
		void			badImput(std::string const &line);
		void			checkEmptyLine(std::string const &line) const;
		void			checkMultiplierFormat(std::string const &line);
		void			checkFormat(std::string const &line);
		void			checkYear(std::string const &line);
		void			checkData(void);
		void			checkImput(std::string const fileName);
		void			handleImput(std::string const fileName);
		std::ifstream	_infile;
		unsigned int	_currentYear;
		unsigned int	_currentMonth;
		unsigned int	_currentDay;
		enum e_format
		{
    		DELIMITER1 = 4,
			DELIMITER2 = 7,
			DELIMITER3 = 10,
			DELIMITER5 = 11,
			DELIMITER4 = 12
		};
};

#endif
