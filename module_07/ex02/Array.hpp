/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:32:38 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/23 16:50:31 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

#include <iostream>
#include <string>

template<typename T>
class	Array
{
	public:
		Array(void);
		Array(unsigned int n);
		~Array(void);
		Array(Array const &src);
		Array	&operator=(Array const &rhs);
		T		&operator[](size_t index);
		T const	&operator[](size_t index) const;
		size_t	size(void) const;
		class	outOfRangeException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
	private:
		T				*_elements;
		unsigned int	_size;
};

#include "Array.tpp"
#endif
