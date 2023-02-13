/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:40:03 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/13 17:47:31 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(void)
{
	this->_first_name = "";
	this->_last_name = "";
	this->_nickname = "";
	this->_phone_number = "";
	this->_darkest_secret = "";
	// std::cout << "constructor called" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	// std::cout << "destructor called" << std::endl;
	return ;
}

void	Contact::get_contact_data(void)
{
	std::string	cout_message[5] = 
	{"First Name", "Last Name", "Nickname", "Phone Number", "Darkest Secret"};
	std::string	data[5];

	for (int i = 0; i < 5; i++)
	{
		std::cout << cout_message[i] << ": ";
		std::getline(std::cin, data[i]);
	}
	set_first_name(data[0]);
	std::cout << get_first_name() << std::endl;
}

void	Contact::set_first_name(std::string first_name)
{
	this->_first_name = first_name;
	return ;
}

std::string	Contact::get_first_name(void)
{
	return (this->_first_name);
}
