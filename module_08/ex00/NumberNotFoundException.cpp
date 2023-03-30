/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NumberNotFoundException.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/30 19:20:50 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NumberNotFoundException.hpp"

NumberNotFoundException::NumberNotFoundException(void)
{
	return ;
}

NumberNotFoundException::NumberNotFoundException(NumberNotFoundException const &src)
{
	*this = src;
	return ;
}

NumberNotFoundException	&NumberNotFoundException::operator=(NumberNotFoundException const &rhs)
{
	if (this != &rhs)
	{
		;
	}
	return (*this);
}

NumberNotFoundException::~NumberNotFoundException(void) throw()
{
	return ;
}

const char *NumberNotFoundException::what(void) const throw()
{
	return ("easyfind: error: number not found exception 🔎❓❓❓");
}
