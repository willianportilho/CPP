/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:58:14 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/10 22:44:32 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H

#include <string>
#include <iostream>
#include <stack>
#include <stdlib.h>
#include "Exceptions.hpp"

class	RPN
{
	public:
		RPN(void);
		RPN(RPN const &src);
		~RPN(void);
		RPN							&operator=(RPN const &rhs);
		void						reversePolishNotation(std::string expression);
	private:
		long long int				_operandA;
		long long int				_operandB;
		long long int				_result;
		char						_operator;
		std::stack<long long int>	_stack;
		bool						_isValidCharacter(char c);
		void						_checkCharacters(std::string &expression);
		void						_removeLeadingZeros(std::string &expression);
		void						_checkValues(std::string &expression);
		void						_removeSpaces(std::string &expression);
		void						_checkMinimumExpression(std::string &expression);
		void						_handleExpression(std::string &expression);
		bool						_isOperator(char c);
		void						_calc(void);
		void						_getOperation(char operatorType);
		void						_checkFinalResult(void);
		void						_calcExpression(std::string &expression);
		void						_printResult(void);
		const char					_plus;
		const char					_minus;
		const char					_multiple;
		const char					_divide;
		const char					_space;
		const char					_zero;
		enum	e_limits
		{
			VALUE_MIN = -9999999999999999,
			VALUE_MAX = 9999999999999999
		};
};

#endif
