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

MutantStack::MutantStack(void)
{
	std::cout << "default MutantStack constructor called." << std::endl;
	return ;
}

MutantStack::MutantStack(MutantStack const &src)
{
	*this = src;
	std::cout << "copy MutantStack constructor called" << std::endl;
	return ;
}

MutantStack::~MutantStack(void)
{
	std::cout << "destructor MutantStack called" << std::endl;
	return ;
}

MutantStack	&MutantStack::operator=(MutantStack const &rhs)
{
	if (this != &rhs)
	{
		;
	}
	std::cout << "assignment copy MutantStack called" << std::endl;
	return (*this);
}
