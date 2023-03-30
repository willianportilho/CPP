/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:45:00 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/30 16:44:30 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

#include <iostream>
#include <exception>
#include <limits>
#include <vector>
#include <algorithm>

class	Span
{
	public:
		Span(unsigned int N);
		Span(Span const &src);
		~Span(void);
		Span			&operator=(Span const &rhs);
		unsigned int	getN(void) const;
		unsigned int	getAmountN(void) const;
		void			setAmountN(unsigned int amount_n);
		void			addNumber(unsigned long int number);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		void			addManyNumbers(std::vector<unsigned int>::iterator it_begin, std::vector<unsigned int>::iterator it_end);
		class	NumberLimitReachedException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
		class	OverflowException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
		class	SpanNotFoundException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
		class	EmptyVectorException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
	private:
		Span(void);
		unsigned int				_n;
		unsigned int				_amount_n;
		std::vector<unsigned int>	_vector;
};

#endif
