/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook copy.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:40:03 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/13 08:23:16 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "constructor called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "destructor called" << std::endl;
	return ;
}

void	PhoneBook::bar(void) const
{
	std::cout << "member function bar called" << std::endl;
	return ;
}
