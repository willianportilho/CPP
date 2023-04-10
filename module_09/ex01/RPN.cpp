/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/10 01:41:37 by wportilh         ###   ########.fr       */
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

void	RPN::_checkExpression(std::string &expression)
{
	if (expression.empty())
		throw Exceptions("empty expression");
	for (int i = 0; expression[i]; i++)
	{
		if ((!isdigit(expression[i])) && (expression[i] != ' ')
		&& (expression[i] != '+') && (expression[i] != '-'))
			throw Exceptions("invalid character(s)");
	}

	return ;
}

void	RPN::reversePolishNotation(std::string expression)
{
	_checkExpression(expression);

	return ;
}
