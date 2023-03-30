/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IndexOutOfRangeException.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/30 19:33:49 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INDEXOUTOFRANGEEXCEPTION_H
# define INDEXOUTOFRANGEEXCEPTION_H

#include <exception>

class	IndexOutOfRangeException : public std::exception
{
	public:
		IndexOutOfRangeException(void);
		IndexOutOfRangeException	&operator=(IndexOutOfRangeException const &rhs);
		IndexOutOfRangeException(IndexOutOfRangeException const &src);
		virtual ~IndexOutOfRangeException(void) throw ();
		virtual const char	*what(void) const throw();
	private:
};

#endif
