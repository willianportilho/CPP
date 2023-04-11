/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:38:33 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/06 21:00:24 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exceptions.hpp"

Exceptions::Exceptions(void) : _message("")
{
	return ;
}

Exceptions::Exceptions(std::string const &message) : _message(message)
{
	return ;
}

Exceptions::Exceptions(Exceptions const &src) : _message(src._message)
{
	*this = src;
	return ;
}

Exceptions	&Exceptions::operator=(Exceptions const &rhs)
{
	if (this != &rhs)
		return(*this);
	return (*this);
}

Exceptions::~Exceptions(void) throw()
{
	return ;
}

const char *Exceptions::what(void) const throw()
{
	return (this->_message.c_str());
}
