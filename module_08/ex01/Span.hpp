/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:45:00 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/29 16:17:10 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

#include <iostream>
#include <exception>

class	Span
{
	public:
		Span(unsigned int N);
		Span(Span const &src);
		~Span(void);
		Span			&operator=(Span const &rhs);
		unsigned int	getN(void) const;
		void			addNumber(size_t number);
		class	NumberLimitReachedException : std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
	private:
		Span(void);
		unsigned int	_n;
};

#endif
