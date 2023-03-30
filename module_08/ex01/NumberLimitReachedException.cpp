/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NumberLimitReachedException.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/30 19:26:13 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NumberLimitReachedException.hpp"

NumberLimitReachedException::NumberLimitReachedException(void)
{
	return ;
}

NumberLimitReachedException::NumberLimitReachedException(NumberLimitReachedException const &src)
{
	*this = src;
	return ;
}

NumberLimitReachedException	&NumberLimitReachedException::operator=(NumberLimitReachedException const &rhs)
{
	if (this != &rhs)
	{
		;
	}
	return (*this);
}

NumberLimitReachedException::~NumberLimitReachedException(void) throw()
{
	return ;
}

const char *NumberLimitReachedException::what(void) const throw()
{
	return ("span: error: number limit reached exception 🌡️ 💥");
}
