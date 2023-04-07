/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/06 22:56:22 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) : _infile("")
{
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
	return ;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
		this->_infile.copyfmt(rhs._infile);
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

void	BitcoinExchange::checkImput(std::string const fileName)
{
	if (fileName.empty())
		throw Exceptions("filename is empty");
	this->_infile.open(fileName.c_str());
	if (!this->_infile.is_open())
		throw Exceptions("cannot open the file");

	return ;
}

void	BitcoinExchange::checkBreakLine(std::string const line) const
{
	if (line == "")
			throw Exceptions("empty line detected");
	return ;
}

void	BitcoinExchange::checkData(void)
{
	std::string	line;

	std::getline(this->_infile, line);
	if (line != "date | value")
		throw Exceptions("wrong header format");
	while (std::getline(this->_infile, line))
	{
		checkBreakLine(line);
	}
	checkBreakLine(line);
	
	return ;
}

void	BitcoinExchange::handleImput(std::string const fileName)
{
	checkImput(fileName);
	checkData();

	return ;
}

void	BitcoinExchange::exchange(std::string const fileName)
{
	handleImput(fileName);
	return ;
}
