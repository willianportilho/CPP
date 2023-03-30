/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpanNotFoundException.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/30 19:30:12 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpanNotFoundException.hpp"

SpanNotFoundException::SpanNotFoundException(void)
{
	return ;
}

SpanNotFoundException::SpanNotFoundException(SpanNotFoundException const &src)
{
	*this = src;
	return ;
}

SpanNotFoundException	&SpanNotFoundException::operator=(SpanNotFoundException const &rhs)
{
	if (this != &rhs)
	{
		;
	}
	return (*this);
}

SpanNotFoundException::~SpanNotFoundException(void) throw()
{
	return ;
}

const char *SpanNotFoundException::what(void) const throw()
{
	return ("span: error: span not found exception, because there's only one (or zero) number(s) added 🔎❓❓❓");
}
