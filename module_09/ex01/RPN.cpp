/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/10 15:32:25 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) : _plus('+'), _minus('-'), _multiple('*'), _divide('/'), _space(' ')
{
	return ;
}

RPN::RPN(RPN const &src) : _plus(src._plus), _minus(src._minus),
_multiple(src._multiple), _divide(src._divide), _space(src._space)
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

int		RPN::_isValidCharacter(char c)
{
	if ((!isdigit(c)) && (c != this->_plus) && (c != this->_minus)
	&& (c != this->_multiple) && (c != this->_divide) && (c != this->_space))
		return (false);
	
	return (true);
}

void	RPN::_checkExpressionCharacters(std::string &expression)
{
	if (expression.empty())
		throw Exceptions("empty expression");
	for (int i = 0; expression[i]; i++)
	{
		if (_isValidCharacter(expression[i]) == false)
			throw Exceptions("invalid character(s)");
	}

	return ;
}

void	RPN::reversePolishNotation(std::string expression)
{
	_checkExpressionCharacters(expression);

	return ;
}
