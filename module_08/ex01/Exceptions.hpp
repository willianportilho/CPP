/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:38:37 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/06 20:58:45 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONS_H
# define EXCEPTIONS_H

#include <exception>
#include <string>

class	Exceptions : public std::exception
{
	public:
		Exceptions(std::string const &message);
		Exceptions	&operator=(Exceptions const &rhs);
		Exceptions(Exceptions const &src);
		virtual	~Exceptions(void) throw ();
		virtual const char	*what(void) const throw();
	private:
		Exceptions(void);
		std::string const	_message;
};

#endif
