/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NumberLimitReachedException copy.hpp               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/30 19:25:08 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBERLIMITREACHEDEXCEPTION_H
# define NUMBERLIMITREACHEDEXCEPTION_H

#include <exception>

class	NumberLimitReachedException : public std::exception
{
	public:
		NumberLimitReachedException(void);
		NumberLimitReachedException	&operator=(NumberLimitReachedException const &rhs);
		NumberLimitReachedException(NumberLimitReachedException const &src);
		virtual ~NumberLimitReachedException(void) throw ();
		virtual const char	*what(void) const throw();
	private:
};

#endif
