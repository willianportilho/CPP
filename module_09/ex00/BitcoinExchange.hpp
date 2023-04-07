/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:58:14 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/06 22:09:03 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

#include <string>
#include <iostream>
#include <fstream>
#include "Exceptions.hpp"

class	BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange	&operator=(BitcoinExchange const &rhs);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange(void);
		void	exchange(std::string const fileName);
	private:
		void	handleImput(std::string const fileName);
};

#endif
