/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/09 22:14:06 by wportilh         ###   ########.fr       */
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
		this->_mapDb.clear();
		this->_mapDb = rhs._mapDb;
	}

	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

void	BitcoinExchange::_get_time(void)
{
	time_t	now = time(0);
	tm		*localTime = localtime(&now);

	this->_currentYear =	localTime->tm_year + 1900;
	this->_currentMonth =	localTime->tm_mon + 1;
	this->_currentDay =		localTime->tm_mday;

	return ;
}

bool	BitcoinExchange::_isLeapYear(unsigned int const year) const
{
	return ((year % 4 == 0) && ((year % 100 != 0) || year % 400 == 0));
}

bool	BitcoinExchange::_isValidDate(unsigned int day, unsigned int month, unsigned int year)
{
	unsigned int	maxDays = 31;

	if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
		maxDays = 30;
	else if (month == 2)
		_isLeapYear(year) ? maxDays = 29 : maxDays = 28;
	if (day > maxDays)
		return (false);

	return (true);
}

void	BitcoinExchange::_openImput(std::string const fileName)
{
	if (fileName.empty())
		throw Exceptions("filename is empty");
	this->_infile.open(fileName.c_str());
	if (!this->_infile.is_open())
		throw Exceptions("could not open file.");

	return ;
}

void	BitcoinExchange::_checkEmptyLine(std::string const &line) const
{
	if (line.empty())
			throw Exceptions("empty line detected");

	return ;
}

void	BitcoinExchange::_badImput(std::string const &line)
{
	return (throw Exceptions("bad imput => " + line));
}

void	BitcoinExchange::_checkFloatFormat(std::string const &line, std::string const &completeLine)
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
			_badImput(completeLine);
	}
	if ((amount_dot > 1) || (amount_dot && line[0] == '.') || (amount_dot && line[line.size() - 1] == '.'))
		_badImput(completeLine);
	else if ((amount_signal > 1) || (amount_signal && line[0] != '+'))
		_badImput(completeLine);
	
	return ;
}

void	BitcoinExchange::_checkFormat(std::string const &line)
{
	if ((line.size() < MINIMUM_LINE_SIZE)
	|| (line[DELIMITER1] != '-') || (line[DELIMITER2] != '-')
	|| (line[DELIMITER3] != ' ') || (line[DELIMITER4] != ' ')
	|| (line[DELIMITER5] != '|'))
		_badImput(line);
	for (int i = 0; i < 10; i++)
	{
		if ((i != DELIMITER1) && (i != DELIMITER2) && (i != DELIMITER3))
		{
			if (!isdigit(line[i]))
				_badImput(line);
		}
	}
	_checkFloatFormat(line.substr(13, line.size() - 1), line);

	return ;
}

void	BitcoinExchange::_checkYear(std::string const &line)
{
	int year	= atoi(line.substr(0, 4).c_str());

	if (year < BITCOIN_YEAR_FOUNDATION)
		throw Exceptions("bitcoin mining emerged from january.02.2009");
	else if (year > this->_currentYear)
		throw Exceptions("the searched date is later than the current date");

	return ;
}

void	BitcoinExchange::_checkMonth(std::string const &line)
{
	int month	= atoi(line.substr(5, 2).c_str());

	if ((month < 1) || (month > 12))
		throw Exceptions("the searched month is out of range");

	return ;
}

void	BitcoinExchange::_checkDay(std::string const &line)
{
	int	year	= atoi(line.substr(0, 4).c_str());
	int	month	= atoi(line.substr(5, 2).c_str());
	int	day		= atoi(line.substr(8, 2).c_str());

	if ((day < 1) || (day > 31))
		throw Exceptions("the searched day is out of range");
	else if ((year == BITCOIN_YEAR_FOUNDATION) && (month == 1) && (day == 1))
		throw Exceptions("bitcoin mining emerged from january.02.2009");
	else if (!_isValidDate(day, month, year))
		throw Exceptions("impossible date");

	return ;
}

void	BitcoinExchange::_checkMultiplier(std::string const &line)
{
	const char	*multiplier = line.substr(13, line.size() - 1).c_str();

	if (std::atof(multiplier) > MULTIPLIER_MAX)
		throw Exceptions("too large a number.");

	return ;
}

void	BitcoinExchange::_printResult(std::string const dateWithDelimiters, float multipler, float result) const
{
	std::cout << dateWithDelimiters << " => " << multipler << " = " << result << std::endl;

	return ;
}

void	BitcoinExchange::_bitCoinResult(std::string line)
{
	std::string	dateWithDelimiters = line.substr(0, 10);
	line.erase(DELIMITER1, 1);
	line.erase((DELIMITER2 - 1), 1);
	unsigned int	date		= atoi(line.substr(0, 8).c_str());
	float			multipler	= strtof(line.substr(11, line.size() - 1).c_str(), NULL);
	float			result;

	std::map<unsigned int, float>::iterator	it;
	it = _mapDb.find(date);
	if (it != this->_mapDb.end())
	{
		result = this->_mapDb[date] * multipler;
		_printResult(dateWithDelimiters, multipler, result);
		return ;
	}
	else
	{
		for (it = _mapDb.begin(); it != _mapDb.end(); it++)
		{
			std::map<unsigned int, float>::iterator	nextIt = it;
			++nextIt;
			if (((date >= it->first) && (nextIt == _mapDb.end()))
			|| ((date >= it->first) && (date < nextIt->first)))
			{
				result = it->second * multipler;
				_printResult(dateWithDelimiters, multipler, result);
				return ;
			}
		}
		_badImput(line);
	}

	return ;
}

void	BitcoinExchange::_handleDataImput(std::string const &fileName)
{
	_openImput(fileName);
	std::string	line;
	std::getline(this->_infile, line);
	if (line != "date | value")
		throw Exceptions("wrong header format: " + fileName);
	while (std::getline(this->_infile, line))
	{
		try
		{	
			_checkEmptyLine(line);
			_checkFormat(line);
			_checkYear(line);
			_checkMonth(line);
			_checkDay(line);
			_checkMultiplier(line);
			_bitCoinResult(line);
		}
		catch(std::exception const &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	this->_infile.close();
	
	return ;
}

void	BitcoinExchange::_checkDbFormat(std::string const &line)
{
	if ((line.size() < MINIMUM_LINE_SIZE - 2)
	|| (line[DELIMITER1] != '-') || (line[DELIMITER2] != '-')
	|| (line[DELIMITER3] != ','))
		_badImput(line);
	for (int i = 0; i < 10; i++)
	{
		if ((i != DELIMITER1) && (i != DELIMITER2) && (i != DELIMITER3))
		{
			if (!isdigit(line[i]))
				_badImput(line);
		}
	}
	_checkFloatFormat(line.substr(11, line.size() - 1), line);

	return ;
}

void	BitcoinExchange::_openDataBase(void)
{
	this->_infileDb.open("data.csv");
	if (!this->_infileDb.is_open())
		throw Exceptions("could not open data.csv.");

	return ;
}

void	BitcoinExchange::_checkExchangeRate(std::string const &line)
{
	const char	*multiplier = line.substr(11, line.size() - 1).c_str();

	if (std::atof(multiplier) > EXCHANGE_RATE_MAX)
		throw Exceptions("too large a number: data.csv");

	return ;
}

void	BitcoinExchange::_fillMapDataBase(std::string line)
{
	line.erase(DELIMITER1, 1);
	line.erase((DELIMITER2 - 1), 1);
	unsigned int	date = atoi(line.substr(0, 8).c_str());
	float			rateExchange = strtof(line.substr(9, line.size() - 1).c_str(), NULL);
	this->_mapDb[date] = rateExchange;

	return ;
}

void	BitcoinExchange::_handleDataBase(void)
{
	_openDataBase();
	std::string	line;
	std::getline(this->_infileDb, line);
	if (line != "date,exchange_rate")
		throw Exceptions("wrong header format: data.csv");
	_get_time();
	while (std::getline(this->_infileDb, line))
	{
		_checkEmptyLine(line);
		_checkDbFormat(line);
		_checkYear(line);
		_checkMonth(line);
		_checkDay(line);
		_checkExchangeRate(line);
		_fillMapDataBase(line);
	}
	this->_infileDb.close();

	return ;
}

void	BitcoinExchange::exchange(std::string const fileName)
{
	_handleDataBase();
	_handleDataImput(fileName);

	return ;
}
