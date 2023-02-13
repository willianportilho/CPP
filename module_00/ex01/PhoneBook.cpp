/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:40:03 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/13 20:57:16 by wportilh         ###   ########.fr       */
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

	if (PhoneBook::amount_of_contacts >= 8)
		index = 0;
	tmp.get_contact_data();
	// std::cout << "add contact called" << std::endl;
	contacts[PhoneBook::index].set_first_name(tmp.get_first_name());
	contacts[PhoneBook::index].set_last_name(tmp.get_last_name());
	contacts[PhoneBook::index].set_nickname(tmp.get_nickname());
	contacts[PhoneBook::index].set_phone_number(tmp.get_phone_number());
	contacts[PhoneBook::index].set_darkest_secret(tmp.get_darkest_secret());
	// std::cout << contacts[0].get_first_name() << std::endl;
	// std::cout << contacts[0].get_last_name() << std::endl;
	// std::cout << contacts[0].get_nickname() << std::endl;
	// std::cout << contacts[0].get_phone_number() << std::endl;
	// std::cout << contacts[0].get_darkest_secret() << std::endl;
	// std::cout << contacts[1].get_first_name() << std::endl;
	// std::cout << contacts[1].get_last_name() << std::endl;
	// std::cout << contacts[1].get_nickname() << std::endl;
	// std::cout << contacts[1].get_phone_number() << std::endl;
	// std::cout << contacts[1].get_darkest_secret() << std::endl;
	PhoneBook::amount_of_contacts += 1;
	PhoneBook::index += 1;
}

void	PhoneBook::search_contact(void)
{
	std::cout << "search contact called" << std::endl;
}

int	PhoneBook::amount_of_contacts = 0;

int	PhoneBook::index = 0;