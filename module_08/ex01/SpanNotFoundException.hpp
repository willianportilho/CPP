/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpanNotFoundException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/30 19:29:47 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPANNOTFOUNDEXCEPTION_H
# define SPANNOTFOUNDEXCEPTION_H

#include <exception>

class	SpanNotFoundException : public std::exception
{
	public:
		SpanNotFoundException(void);
		SpanNotFoundException	&operator=(SpanNotFoundException const &rhs);
		SpanNotFoundException(SpanNotFoundException const &src);
		virtual ~SpanNotFoundException(void) throw ();
		virtual const char	*what(void) const throw();
	private:
};

#endif
