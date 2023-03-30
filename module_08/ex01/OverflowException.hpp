/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OverflowException.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/30 19:27:46 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OVERFLOWEXCEPTION_H
# define OVERFLOWEXCEPTION_H

#include <exception>

class	OverflowException : public std::exception
{
	public:
		OverflowException(void);
		OverflowException	&operator=(OverflowException const &rhs);
		OverflowException(OverflowException const &src);
		virtual ~OverflowException(void) throw ();
		virtual const char	*what(void) const throw();
	private:
};

#endif
