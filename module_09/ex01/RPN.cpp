/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/10 17:54:06 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) : _plus('+'), _minus('-'), _multiple('*'), _divide('/'), _space(' '), _zero('0')
{
	return ;
}

RPN::RPN(RPN const &src) : _plus(src._plus), _minus(src._minus),
_multiple(src._multiple), _divide(src._divide), _space(src._space), _zero(src._zero)
{
	*this = src;

	return ;
}

RPN	&RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
	{
		// this->_stack.;
		// this->_stack = rhs._stack;
		;
	}

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

void	RPN::_checkCharacters(std::string &expression)
{
	for (int i = 0; expression[i]; i++)
	{
		if (_isValidCharacter(expression[i]) == false)
			throw Exceptions("invalid character(s)");
	}

	return ;
}

void	RPN::_checkMinimumExpression(std::string &expression)
{
	int	amountOperators = 0, amountdigits = 0;

	for (int i = 0; expression[i]; i++)
	{
		if (isdigit(expression[i]))
			amountdigits++;
		else if ((expression[i] == this->_plus) || (expression[i] == this->_minus)
		|| (expression[i] == this->_multiple) || (expression[i] == this->_divide))
			amountOperators++;			
	}
	if ((amountdigits < 2) || (amountOperators == 0))
		throw Exceptions("invalid expression");
	return ;
}

void	RPN::_removeLeadingZeros(std::string &expression)
{
	for (int i = 0; expression[i]; i++)
	{
		if ((expression[i] == this->_zero) && (isdigit(expression[i + 1])))
		{
			expression.erase(i, 1);
			i--;
		}
	}

	return ;
}

void	RPN::_checkValues(std::string &expression)
{
	for (int i = 0; expression[i]; i++)
	{
		if ((isdigit(expression[i])) && (isdigit(expression[i + 1])))
			throw Exceptions("invalid value");
	}

	return ;
}

void	RPN::_removeSpaces(std::string &expression)
{
	for (int i = 0; expression[i]; i++)
	{
		if (expression[i] == this->_space)
		{
			expression.erase(i, 1);
			i--;
		}
	}

	return ;
}

void	RPN::_handleExpression(std::string &expression)
{
	if (expression.empty())
		throw Exceptions("empty expression");
	_checkCharacters(expression);
	_removeLeadingZeros(expression);
	_checkValues(expression);
	_removeSpaces(expression);
	_checkMinimumExpression(expression);

	return ;
}

void	RPN::_fillStack(std::string &expression)
{
	for (int i = 0; expression[i]; i++)
		this->_stack.push(expression[i]);	

	return ;
}

void	RPN::reversePolishNotation(std::string expression)
{
	_handleExpression(expression);
	_fillStack(expression);

	return ;
}
