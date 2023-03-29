/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:45:03 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/29 15:10:38 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{
	std::cout << "default Span constructor called" << std::endl;
	return ;
}

Span::Span(unsigned int N) : _n(N)
{
	std::cout << "named Span constructor called with parameter N(" << this->getN() << ")" << std::endl;
	return ;
}

Span::Span(Span const &src)
{
	*this = src;
	std::cout << "copy Span constructor called" << std::endl;
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
	std::cout << "destructor Span called" << std::endl;
	return ;
}

unsigned int	Span::getN(void) const
{
	return (this->_n);
}
