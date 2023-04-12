/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/12 13:37:56 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) :	_operandA(0), _operandB(0), _result(0),
					_operator(' '), _PLUS('+'), _MINUS('-'),
					_MULTIPLE('*'), _DIVIDE('/'), _SPACE(' '),
					_ZERO('0')
{
	return ;
}

RPN::RPN(RPN const &src) :	_PLUS(src._PLUS), _MINUS(src._MINUS),
							_MULTIPLE(src._MULTIPLE), _DIVIDE(src._DIVIDE),
							_SPACE(src._SPACE), _ZERO(src._ZERO)
{
	*this = src;

	return ;
}

RPN	&RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
	{
		while (!this->_stack.empty())
			this->_stack.pop();
		this->_stack = rhs._stack;
		this->_operator = rhs._operator;
		this->_operandA	= rhs._operandA;
		this->_operandB	= rhs._operandB;
		this->_result	= rhs._result;
	}

	return (*this);
}

RPN::~RPN(void)
{
	return ;
}

bool		RPN::_isValidCharacter(char c)
{
	if ((!isdigit(c)) && (c != _PLUS) && (c != _MINUS)
	&& (c != _MULTIPLE) && (c != _DIVIDE) && (c != _SPACE))
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
		else if ((expression[i] == _PLUS) || (expression[i] == _MINUS)
		|| (expression[i] == _MULTIPLE) || (expression[i] == _DIVIDE))
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
		if ((expression[i] == _ZERO) && (isdigit(expression[i + 1])))
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
		if (expression[i] == _SPACE)
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

bool	RPN::_isOperator(char c)
{
	if ((c != _PLUS) && (c != _MINUS)
	&& (c != _MULTIPLE) && (c != _DIVIDE))
		return (false);

	return (true);
}

void	RPN::_getOperation(char operatorType)
{
	this->_operandB = this->_stack.top();
	this->_stack.pop();
	this->_operandA = this->_stack.top();
	this->_stack.pop();

	this->_operator = operatorType;

	return ;
}

void	RPN::_calc(void)
{
	switch (this->_operator)
	{
	case '+':
		this->_result = this->_operandA + this->_operandB;
		break;
	case '-':
		this->_result = this->_operandA - this->_operandB;
		break;
	case '*':
		this->_result = this->_operandA * this->_operandB;
		break;
	case '/':
		if (this->_operandB == 0)
			throw Exceptions("division by 0 detected");
		this->_result = this->_operandA / this->_operandB;
		break;
	default:
		throw Exceptions("something went wrong");
		break;
	}

	if (this->_result > VALUE_MAX)
		throw Exceptions("overflow detected");
	else if (this->_result < VALUE_MIN)
		throw Exceptions("underflow detected");
	
	this->_stack.push(this->_result);

	return ;
}

void	RPN::_checkFinalResult(void)
{
	if (this->_stack.size() != 1)
		throw Exceptions("invalid expression");

	return ;
}

void	RPN::_calcExpression(std::string &expression)
{
	for (int i = 0; expression[i]; i++)
	{
		if (isdigit(expression[i]))
			this->_stack.push(expression[i] - '0');
		else if (_isOperator(expression[i]) == true)
		{
			if (this->_stack.size() > 1)
			{
				_getOperation(expression[i]);
				_calc();
			}
			else
				throw Exceptions("invalid expression");
		}
	}
	_checkFinalResult();

	return ;
}

void	RPN::_printResult(void)
{
	std::cout << this->_stack.top() << std::endl;

	return ;
}

void	RPN::reversePolishNotation(std::string expression)
{
	_handleExpression(expression);
	_calcExpression(expression);
	_printResult();

	return ;
}
