/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:45:03 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/30 15:38:01 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _n(0), _amount_n(0)
{
	// std::cout << "default Span constructor called" << std::endl;
	return ;
}

Span::Span(unsigned int N) : _n(N), _amount_n(0)
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
		this->_n = rhs.getN();
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
	return (this->_amount_n);
}

void	Span::setAmountN(unsigned int amount_n)
{
	this->_amount_n = amount_n;
	return ;
}

void	Span::addNumber(long unsigned int number)
{
	if (this->getAmountN() < this->getN())
	{
		if (number > static_cast<unsigned int>(std::numeric_limits<int>::max()))
			throw Span::OverflowException();
		this->_vector.push_back(number);
		this->setAmountN(this->getAmountN() + 1);
	}
	else
		throw Span::NumberLimitReachedException();
	// if (this->getAmountN() == this->getN())
	// {
	// 	for (std::vector<unsigned int>::iterator it = _vector.begin(); it != this->_vector.end(); it++)
	// 		std::cout << *it << std::endl;
	// }
	return ;
}

unsigned int	Span::shortestSpan(void)
{
	if (this->getAmountN() <= 1)
		throw Span::SpanNotFoundException();

	std::vector<unsigned int>	vector_copy(this->_vector.size());
	std::copy(this->_vector.begin(), this->_vector.end(), vector_copy.begin());

	std::sort(vector_copy.begin(), vector_copy.end());

	unsigned int	shortest_span = std::numeric_limits<unsigned int>::max();
	for (std::vector<unsigned int>::iterator it = vector_copy.begin(); it != vector_copy.end(); it++)
	{
		for (std::vector<unsigned int>::iterator it2 = it + 1; it2 != vector_copy.end(); it2++)
		{
			if (((*it2 - *it) < shortest_span))
				shortest_span = *it2 - *it;
		}
	}

	return (shortest_span);
}

unsigned int	Span::longestSpan(void)
{
	if (this->getAmountN() <= 1)
		throw Span::SpanNotFoundException();

	std::vector<unsigned int>	vector_copy(this->_vector.size());
	std::copy(this->_vector.begin(), this->_vector.end(), vector_copy.begin());

	std::sort(vector_copy.begin(), vector_copy.end());

	std::vector<unsigned int>::iterator	it = vector_copy.begin();
	std::vector<unsigned int>::iterator	it2 = vector_copy.end() - 1;
	unsigned int	longestSpan = *it2 - *it;

	return (longestSpan);
}

void	addManyNumbers(std::vector<unsigned int> it_begin, std::vector<unsigned int> it_end)
{
	(void)it_begin;
	(void)it_end;
	return ;	
}

const char	*Span::NumberLimitReachedException::what(void) const throw()
{
	return ("span: error: number limit reached exception 🌡️ 💥");
}

const char	*Span::OverflowException::what(void) const throw()
{
	return ("span: error: overflow exception ↗️ 💥");
}

const char	*Span::SpanNotFoundException::what(void) const throw()
{
	return ("span: error: span not found exception 🔎❓❓❓");
}
