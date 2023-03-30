/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EmptyVectorException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/30 19:32:10 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EmptyVectorException.hpp"

EmptyVectorException::EmptyVectorException(void)
{
	return ;
}

EmptyVectorException::EmptyVectorException(EmptyVectorException const &src)
{
	*this = src;
	return ;
}

EmptyVectorException	&EmptyVectorException::operator=(EmptyVectorException const &rhs)
{
	if (this != &rhs)
	{
		;
	}
	return (*this);
}

EmptyVectorException::~EmptyVectorException(void) throw()
{
	return ;
}

const char *EmptyVectorException::what(void) const throw()
{
	return ("span: error: empty vector exception 🔎❓❓❓");
}
