/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IndexOutOfRangeException.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/30 19:34:07 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IndexOutOfRangeException.hpp"

IndexOutOfRangeException::IndexOutOfRangeException(void)
{
	return ;
}

IndexOutOfRangeException::IndexOutOfRangeException(IndexOutOfRangeException const &src)
{
	*this = src;
	return ;
}

IndexOutOfRangeException	&IndexOutOfRangeException::operator=(IndexOutOfRangeException const &rhs)
{
	if (this != &rhs)
	{
		;
	}
	return (*this);
}

IndexOutOfRangeException::~IndexOutOfRangeException(void) throw()
{
	return ;
}

const char *IndexOutOfRangeException::what(void) const throw()
{
	return ("span: error: index out range exception ↗️ 💥");
}
