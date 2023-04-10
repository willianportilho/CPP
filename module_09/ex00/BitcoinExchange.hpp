/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:58:14 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/09 22:26:36 by wportilh         ###   ########.fr       */
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
		BitcoinExchange					&operator=(BitcoinExchange const &rhs);
		void							exchange(std::string const fileName);
	private:
		bool							_isLeapYear(unsigned int const year) const;
		bool							_isValidDate(unsigned int day, unsigned int month, unsigned int year);
		void							_get_time(void);
		void							_badImput(std::string const &line);
		void							_checkEmptyLine(std::string const &line) const;
		void							_checkFloatFormat(std::string const &line, std::string const &completeLine);
		void							_checkFormat(std::string const &line);
		void							_checkYear(std::string const &line);
		void							_checkMonth(std::string const &line);
		void							_checkDay(std::string const &line);
		void							_checkMultiplier(std::string const &line);
		void							_printResult(std::string const date, float multipler, float result) const;
		void							_bitCoinResult(std::string line);
		void							_openImput(std::string const fileName);
		void							_fillMapDataBase(std::string line);
		void							_checkExchangeRate(std::string const &line);
		void							_handleImput(std::string const &fileName);
		void							_checkDbFormat(std::string const &line);
		void							_openDataBase(void);
		void							_handleDataBase(void);
		std::map<unsigned int, float>	_mapDb;
		std::ifstream					_infile;
		std::ifstream					_infileDb;
		int								_currentYear;
		int								_currentMonth;
		int								_currentDay;
		enum e_format
		{
    		DELIMITER1 = 4,
			DELIMITER2 = 7,
			DELIMITER3 = 10,
			DELIMITER5 = 11,
			DELIMITER4 = 12,
			MINIMUM_LINE_SIZE = 14,
			MULTIPLIER_MAX = 1000,
			BITCOIN_YEAR_FOUNDATION = 2009,
			EXCHANGE_RATE_MAX = 2147483647
		};
};

#endif
