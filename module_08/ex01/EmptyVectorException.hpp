/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EmptyVectorException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/30 19:31:51 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EMPTYVECTOREXCEPTION_H
# define EMPTYVECTOREXCEPTION_H

#include <exception>

class	EmptyVectorException : public std::exception
{
	public:
		EmptyVectorException(void);
		EmptyVectorException	&operator=(EmptyVectorException const &rhs);
		EmptyVectorException(EmptyVectorException const &src);
		virtual ~EmptyVectorException(void) throw ();
		virtual const char	*what(void) const throw();
	private:
};

#endif
