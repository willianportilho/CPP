/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:45:00 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/29 15:08:51 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

#include <iostream>

class	Span
{
	public:
		Span(unsigned int N);
		Span(Span const &src);
		~Span(void);
		Span			&operator=(Span const &rhs);
		unsigned int	getN(void) const;
	private:
		Span(void);
		unsigned int	_n;
};

#endif
