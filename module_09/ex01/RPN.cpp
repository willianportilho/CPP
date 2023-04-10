/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    RPN.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/09 23:27:18 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
	return ;
}

RPN::RPN(RPN const &src)
{
	*this = src;

	return ;
}

RPN	&RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
		return (*this);
	return (*this);
}

RPN::~RPN(void)
{
	return ;
}
