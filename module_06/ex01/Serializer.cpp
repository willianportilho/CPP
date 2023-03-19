/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:49:12 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/19 19:22:20 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	return ;
}

Serializer::Serializer(Serializer const &src)
{
	*this = src;
	return ;
}

Serializer::~Serializer(void)
{
	return ;
}

Serializer	&Serializer::operator=(Serializer const &rhs)
{
	if (this != &rhs)
	{
		;
	}
	return (*this);
}
