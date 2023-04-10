/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:58:14 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/10 01:41:30 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H

#include <string>
#include <iostream>
#include "Exceptions.hpp"

class	RPN
{
	public:
		RPN(void);
		RPN(RPN const &src);
		~RPN(void);
		RPN		&operator=(RPN const &rhs);
		void	reversePolishNotation(std::string expression);
	private:
		void	_checkExpression(std::string &expression);
};

#endif
