/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NumberNotFoundException.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/30 19:20:07 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NumberNotFoundException_H
# define NumberNotFoundException_H

#include <exception>

class	NumberNotFoundException : public std::exception
{
	public:
		NumberNotFoundException(void);
		NumberNotFoundException	&operator=(NumberNotFoundException const &rhs);
		NumberNotFoundException(NumberNotFoundException const &src);
		virtual ~NumberNotFoundException(void) throw ();
		virtual const char	*what(void) const throw();
	private:
};

#endif
