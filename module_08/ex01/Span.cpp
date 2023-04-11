/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:45:03 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/11 20:39:45 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _n(0), _amountN(0)
{
	// std::cout << "default Span constructor called" << std::endl;
	return ;
}

Span::Span(unsigned int N) : _n(N), _amountN(0)
{
	// std::cout << "named Span constructor called with parameter N(" << this->getN() << ")" << std::endl;
	return ;
}

Span::Span(Span const &src)
{
	*this = src;
	// std::cout << "copy Span constructor called" << std::endl;
	return ;
}

Span	&Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		this->_n = rhs.getN();
		this->_amountN = rhs.getAmountN();
		this->_vector = rhs._vector;
	}
	return (*this);
}

Span::~Span(void)
{
	// std::cout << "destructor Span called" << std::endl;
	return ;
}

unsigned int	Span::getN(void) const
{
	return (this->_n);
}

unsigned int	Span::getAmountN(void) const
{
	return (this->_amountN);
}

unsigned int	Span::getVector(size_t const index) const
{
	if (index >= getAmountN())
		throw Exceptions("index out range exception ↗️ 💥");
	return (this->_vector[index]);
}

void	Span::setAmountN(unsigned int amountN)
{
	this->_amountN = amountN;
	return ;
}

void	Span::setVector(size_t const index, unsigned int const number)
{
	if (index >= getAmountN())
		throw Exceptions("index out range exception ↗️ 💥");
	this->_vector[index] = number;
	return ;
}

void	Span::addNumber(unsigned long int number)
{
	if (this->getAmountN() < this->getN())
	{
		if (number > static_cast<unsigned int>(std::numeric_limits<int>::max()))
			throw Exceptions("overflow exception ↗️ 💥");
		this->_vector.push_back(number);
		this->setAmountN(this->getAmountN() + 1);
	}
	else
		throw Exceptions("number limit reached exception 🌡️ 💥");
	return ;
}

unsigned int	Span::shortestSpan(void)
{
	if (this->getAmountN() <= 1)
		throw Exceptions("span not found exception, because there's only one (or zero) number(s) added 🔎❓❓❓");

	std::vector<unsigned int>	vectorCopy(this->_vector.size());
	std::copy(this->_vector.begin(), this->_vector.end(), vectorCopy.begin());

	std::sort(vectorCopy.begin(), vectorCopy.end());

	unsigned int	shortestSpan = std::numeric_limits<unsigned int>::max();
	for (std::vector<unsigned int>::iterator it = vectorCopy.begin(); it != vectorCopy.end(); it++)
	{
		for (std::vector<unsigned int>::iterator it2 = it + 1; it2 != vectorCopy.end(); it2++)
		{
			if (((*it2 - *it) < shortestSpan))
				shortestSpan = *it2 - *it;
		}
	}

	return (shortestSpan);
}

unsigned int	Span::longestSpan(void)
{
	if (this->getAmountN() <= 1)
		throw Exceptions("span not found exception, because there's only one (or zero) number(s) added 🔎❓❓❓");

	std::vector<unsigned int>	vectorCopy(this->_vector.size());
	std::copy(this->_vector.begin(), this->_vector.end(), vectorCopy.begin());

	std::sort(vectorCopy.begin(), vectorCopy.end());

	std::vector<unsigned int>::iterator	it = vectorCopy.begin();
	std::vector<unsigned int>::iterator	it2 = vectorCopy.end() - 1;
	unsigned int	longestSpan = *it2 - *it;

	return (longestSpan);
}

void	Span::addManyNumbers(std::vector<unsigned int>::iterator itBegin, std::vector<unsigned int>::iterator itEnd)
{
	if (itBegin == itEnd)
		throw Exceptions("empty vector exception 🔎❓❓❓");
	while (itBegin != itEnd)
	{
		this->addNumber(*itBegin);
		itBegin++;
	}
	
	return ;	
}
