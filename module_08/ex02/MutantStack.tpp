/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:49:12 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/11 13:27:19 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(void)
{
	// std::cout << "default MutantStack constructor called." << std::endl;
	return ;
}

template<typename T>
MutantStack<T>::MutantStack(MutantStack const &src) : std::stack<T>(src)
{
	*this = src;
	// std::cout << "copy MutantStack constructor called" << std::endl;
	return ;
}

template<typename T>
MutantStack<T>	&MutantStack<T>::operator=(MutantStack const &rhs)
{
	if (this != &rhs)
		std::stack<T>::operator=(rhs);
	// std::cout << "assignment copy MutantStack called" << std::endl;
	return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack(void)
{
	// std::cout << "destructor MutantStack called" << std::endl;
	return ;
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return (std::stack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin(void)
{
	return (std::stack<T>::c.rbegin());
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return (std::stack<T>::c.end());
}

template<typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend(void)
{
	return (std::stack<T>::c.rend());
}
