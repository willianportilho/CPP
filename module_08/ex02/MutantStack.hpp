/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/11 13:27:07 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

#include <stack>
#include <iostream>

template<typename T>
class	MutantStack : public std::stack<T>
{
	public:
		MutantStack(void);
		MutantStack(MutantStack const &src);
		~MutantStack(void);
		MutantStack	&operator=(MutantStack const &rhs);

		typedef	typename std::stack<T>::container_type::iterator			iterator;
		typedef	typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;
		typedef	typename std::stack<T>::container_type::const_iterator		const_iterator;

		iterator			begin(void);
		reverse_iterator	rbegin(void);
		const_iterator		cbegin(void) const;

		iterator			end(void);
		reverse_iterator	rend(void);
		const_iterator		cend(void);

};

#include "MutantStack.tpp"

#endif
