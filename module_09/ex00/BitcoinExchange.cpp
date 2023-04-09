/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/09 20:17:44 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) : _infile(""), _infileDb(""), _currentYear(0), _currentMonth(0), _currentDay(0)
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
		this->_infileDb.copyfmt(rhs._infileDb);
		this->_currentYear = rhs._currentYear;
		this->_currentMonth = rhs._currentMonth;
		this->_currentDay = rhs._currentDay;
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

	this->_currentYear =	localTime->tm_year + 1900;
	this->_currentMonth =	localTime->tm_mon + 1;
	this->_currentDay =		localTime->tm_mday;

	return ;
}

bool	BitcoinExchange::isLeapYear(unsigned int const year) const
{
	return ((year % 4 == 0) && ((year % 100 != 0) || year % 400 == 0));
}

bool	BitcoinExchange::isValidDate(unsigned int day, unsigned int month, unsigned int year)
{
	unsigned int	maxDays = 31;

	if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
		maxDays = 30;
	else if (month == 2)
		isLeapYear(year) ? maxDays = 29 : maxDays = 28;
	if (day > maxDays)
		return (false);

	return (true);
}

void	BitcoinExchange::openImput(std::string const fileName)
{
	if (fileName.empty())
		throw Exceptions("filename is empty");
	this->_infile.open(fileName.c_str());
	if (!this->_infile.is_open())
		throw Exceptions("could not open file.");

	return ;
}

void	BitcoinExchange::checkEmptyLine(std::string const &line) const
{
	if (line.empty())
			throw Exceptions("empty line detected");

	return ;
}

void	BitcoinExchange::badImput(std::string const &line)
{
	return (throw Exceptions("bad imput => " + line));
}

void	BitcoinExchange::checkFloatFormat(std::string const &line, std::string const &completeLine)
{
	int	amount_dot = 0, amount_signal = 0;

	if (line[0] == '-')
			throw Exceptions("not a positive number.");
	for (long unsigned int i = 0; i < line.size(); i++)
	{
		if (line[i] == '.')
			amount_dot++;
		else if (line[i] == '+')
			amount_signal++;
		else if (!isdigit(line[i]))
			badImput(completeLine);
	}
	if ((amount_dot > 1) || (amount_dot && line[0] == '.') || (amount_dot && line[line.size() - 1] == '.'))
		badImput(completeLine);
	else if ((amount_signal > 1) || (amount_signal && line[0] != '+'))
		badImput(completeLine);
	
	return ;
}

void	BitcoinExchange::checkFormat(std::string const &line)
{
	if ((line.size() < MINIMUM_LINE_SIZE)
	|| (line[DELIMITER1] != '-') || (line[DELIMITER2] != '-')
	|| (line[DELIMITER3] != ' ') || (line[DELIMITER4] != ' ')
	|| (line[DELIMITER5] != '|'))
		badImput(line);
	for (int i = 0; i < 10; i++)
	{
		if ((i != DELIMITER1) && (i != DELIMITER2) && (i != DELIMITER3))
		{
			if (!isdigit(line[i]))
				badImput(line);
		}
	}
	checkFloatFormat(line.substr(13, line.size() - 1), line);

	return ;
}

void	BitcoinExchange::checkYear(std::string const &line)
{
	const char	*year	= line.substr(0, 4).c_str();

	if (atoi(year) < BITCOIN_YEAR_FOUNDATION)
		throw Exceptions("bitcoin mining emerged from january.02.2009");
	else if (atoi(year) > this->_currentYear)
		throw Exceptions("the searched date is later than the current date");

	return ;
}

void	BitcoinExchange::checkMonth(std::string const &line)
{
	const char	*month	= line.substr(5, 2).c_str();

	if ((atoi(month) < 1) || (atoi(month) > 12))
		throw Exceptions("the searched month is out of range");

	return ;
}

void	BitcoinExchange::checkDay(std::string const &line)
{
	const char	*day	= line.substr(8, 2).c_str();
	const char	*year	= line.substr(0, 4).c_str();
	const char	*month	= line.substr(5, 2).c_str();

	if ((atoi(day) < 1) || (atoi(day) > 31))
		throw Exceptions("the searched day is out of range");
	else if ((atoi(year) == BITCOIN_YEAR_FOUNDATION) && (atoi(month) == 1) && (atoi(day) == 1))
		throw Exceptions("bitcoin mining emerged from january.02.2009");
	else if (!isValidDate(atoi(day), atoi(month), atoi(year)))
		throw Exceptions("impossible date");

	return ;
}

void	BitcoinExchange::checkMultiplier(std::string const &line)
{
	const char	*multiplier = line.substr(13, line.size() - 1).c_str();

	if (std::atof(multiplier) > MULTIPLIER_MAX)
		throw Exceptions("too large a number.");

	return ;
}

void	BitcoinExchange::fillMapImput(std::string line)
{
	line.erase(DELIMITER1, 1);
	line.erase((DELIMITER2 - 1), 1);
	unsigned int	date = atoi(line.substr(0, 8).c_str());
	float			rateExchange = strtof(line.substr(11, line.size() - 1).c_str(), NULL);
	this->mapImput[date] = rateExchange;

	return ;
}

void	BitcoinExchange::handleDataImput(std::string const &fileName)
{
	openImput(fileName);
	std::string	line;
	std::getline(this->_infile, line);
	if (line != "date | value")
		throw Exceptions("wrong header format: " + fileName);
	while (std::getline(this->_infile, line))
	{
		try
		{	
			checkEmptyLine(line);
			checkFormat(line);
			checkYear(line);
			checkMonth(line);
			checkDay(line);
			checkMultiplier(line);
			fillMapImput(line);
		}
		catch(std::exception const &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	this->_infile.close();
	
	return ;
}

void	BitcoinExchange::checkDbFormat(std::string const &line)
{
	if ((line.size() < MINIMUM_LINE_SIZE - 2)
	|| (line[DELIMITER1] != '-') || (line[DELIMITER2] != '-')
	|| (line[DELIMITER3] != ','))
		badImput(line);
	for (int i = 0; i < 10; i++)
	{
		if ((i != DELIMITER1) && (i != DELIMITER2) && (i != DELIMITER3))
		{
			if (!isdigit(line[i]))
				badImput(line);
		}
	}
	checkFloatFormat(line.substr(11, line.size() - 1), line);

	return ;
}
void	BitcoinExchange::openDataBase(void)
{
	this->_infileDb.open("data.csv");
	if (!this->_infileDb.is_open())
		throw Exceptions("could not open data.csv.");

	return ;
}

void	BitcoinExchange::checkExchangeRate(std::string const &line)
{
	const char	*multiplier = line.substr(11, line.size() - 1).c_str();

	if (std::atof(multiplier) > EXCHANGE_RATE_MAX)
		throw Exceptions("too large a number: data.csv");

	return ;
}

void	BitcoinExchange::fillMapDataBase(std::string line)
{
	line.erase(DELIMITER1, 1);
	line.erase((DELIMITER2 - 1), 1);
	unsigned int	date = atoi(line.substr(0, 8).c_str());
	float			rateExchange = strtof(line.substr(9, line.size() - 1).c_str(), NULL);
	this->mapDb[date] = rateExchange;

	return ;
}

void	BitcoinExchange::handleDataBase(void)
{
	openDataBase();
	std::string	line;
	std::getline(this->_infileDb, line);
	if (line != "date,exchange_rate")
		throw Exceptions("wrong header format: data.csv");
	get_time();
	while (std::getline(this->_infileDb, line))
	{
		checkEmptyLine(line);
		checkDbFormat(line);
		checkYear(line);
		checkMonth(line);
		checkDay(line);
		checkExchangeRate(line);
		fillMapDataBase(line);
	}
	this->_infileDb.close();

	return ;
}

void	BitcoinExchange::exchange(std::string const fileName)
{
	handleDataBase();
	handleDataImput(fileName);
	// std::map<unsigned int, float>::iterator	it;
	// for (it = mapImput.begin(); it != mapImput.end(); it++)
	// 	std::cout << it->second << std::endl;

	return ;
}
