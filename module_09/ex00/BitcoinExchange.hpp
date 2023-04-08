/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:58:14 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/07 20:46:14 by wportilh         ###   ########.fr       */
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
#include <cstdlib>
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
		void			checkMonth(std::string const &line);
		void			checkDay(std::string const &line);
		bool			isLeapYear(unsigned int const year) const;
		bool			isValidDate(unsigned int day, unsigned int month, unsigned int year);
		void			checkMultiplier(std::string const &line);
		void			handleData(void);
		void			checkImput(std::string const fileName);
		void			handleImput(std::string const fileName);
		std::ifstream	_infile;
		int				_currentYear;
		int				_currentMonth;
		int				_currentDay;
		enum e_format
		{
    		DELIMITER1 = 4,
			DELIMITER2 = 7,
			DELIMITER3 = 10,
			DELIMITER5 = 11,
			DELIMITER4 = 12,
			MINIMUM_LINE_SIZE = 14,
			MULTIPLIER_MAX = 1000,
			BITCOIN_YEAR_FOUNDATION = 2009
		};
};

#endif
