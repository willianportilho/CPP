/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    RPN.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:58:14 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/09 23:31:59 by wportilh         ###   ########.fr       */
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
		RPN					&operator=(RPN const &rhs);
};

#endif
