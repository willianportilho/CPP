/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:58:14 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/10 17:45:09 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H

#include <string>
#include <iostream>
#include <stack>
#include "Exceptions.hpp"

class	RPN
{
	public:
		RPN(void);
		RPN(RPN const &src);
		~RPN(void);
		RPN					&operator=(RPN const &rhs);
		void				reversePolishNotation(std::string expression);
	private:
		std::stack<char>	_stack;
		int					_isValidCharacter(char c);
		void				_checkCharacters(std::string &expression);
		void				_removeLeadingZeros(std::string &expression);
		void				_checkValues(std::string &expression);
		void				_removeSpaces(std::string &expression);
		void				_checkMinimumExpression(std::string &expression);
		void				_handleExpression(std::string &expression);
		void				_fillStack(std::string &expression);
		const char			_plus;
		const char			_minus;
		const char			_multiple;
		const char			_divide;
		const char			_space;
		const char			_zero;
};

#endif
