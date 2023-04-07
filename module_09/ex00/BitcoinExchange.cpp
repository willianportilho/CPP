/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/06 23:27:11 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) : _infile(""), _year(0), _month(0), _day(0)
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
	{
		this->_infile.copyfmt(rhs._infile);
		this->_year = rhs._year;
		this->_month = rhs._month;
		this->_day = rhs._day;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

void	BitcoinExchange::get_time(void)
{
	time_t	now = time(0);
	tm		*localTime = localtime(&now);

	this->_year =	localTime->tm_year;
	this->_month =	localTime->tm_mon;
	this->_day =	localTime->tm_mday;

	std::cout << this->_year << std::endl;
	std::cout << this->_month << std::endl;
	std::cout << this->_day << std::endl;

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

void	BitcoinExchange::checkYear(std::string const &line) const
{
	if (atoi(line.c_str()) < 2009) || atoi(line.c_str()) > 2023)
			throw Exceptions("wrong year format detected");
	return ;
}

void	BitcoinExchange::checkEmptyLine(std::string const &line) const
{
	if (line.empty())
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
		checkEmptyLine(line);
		checkYear(line);
	}
	checkEmptyLine(line);
	
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
