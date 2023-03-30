/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:45:00 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/30 19:35:36 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

#include <iostream>
#include <exception>
#include <limits>
#include <vector>
#include <algorithm>
#include "EmptyVectorException.hpp"
#include "IndexOutOfRangeException.hpp"
#include "NumberLimitReachedException.hpp"
#include "OverflowException.hpp"
#include "SpanNotFoundException.hpp"

class	Span
{
	public:
		Span(unsigned int N);
		Span(Span const &src);
		~Span(void);
		Span			&operator=(Span const &rhs);
		unsigned int	getN(void) const;
		unsigned int	getAmountN(void) const;
		unsigned int	getVector(size_t const index) const;
		void			setAmountN(unsigned int amountN);
		void			setVector(size_t const index, unsigned int const number);
		void			addNumber(unsigned long int number);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		void			addManyNumbers(std::vector<unsigned int>::iterator itBegin, std::vector<unsigned int>::iterator itEnd);
	private:
		Span(void);
		unsigned int				_n;
		unsigned int				_amountN;
		std::vector<unsigned int>	_vector;
};

#endif
