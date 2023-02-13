/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:40:03 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/13 17:09:52 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	// std::cout << "constructor called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	// std::cout << "destructor called" << std::endl;
	return ;
}

void	PhoneBook::add_contact(void)
{
	Contact tmp;

	tmp.get_contact_data();
	// std::cout << "add contact called" << std::endl;
	contacts[0].set_first_name("testando");
	std::cout << contacts[0].get_first_name() << std::endl;
}

void	PhoneBook::search_contact(void)
{
	std::cout << "search contact called" << std::endl;
}
