/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OverflowException.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/30 19:28:13 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OverflowException.hpp"

OverflowException::OverflowException(void)
{
	return ;
}

OverflowException::OverflowException(OverflowException const &src)
{
	*this = src;
	return ;
}

OverflowException	&OverflowException::operator=(OverflowException const &rhs)
{
	if (this != &rhs)
	{
		;
	}
	return (*this);
}

OverflowException::~OverflowException(void) throw()
{
	return ;
}

const char *OverflowException::what(void) const throw()
{
	return ("span: error: overflow exception ↗️ 💥");
}
