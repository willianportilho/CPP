/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:58:14 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/06 23:24:20 by wportilh         ###   ########.fr       */
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
		void			checkYear(std::string const &line) const;
		void			checkEmptyLine(std::string const &line) const;
		void			checkData(void);
		void			checkImput(std::string const fileName);
		void			handleImput(std::string const fileName);
		std::ifstream	_infile;
		unsigned int	_year;
		unsigned int	_month;
		unsigned int	_day;
};

#endif
