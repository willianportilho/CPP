/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:40:03 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/13 18:24:40 by wportilh         ###   ########.fr       */
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
	set_last_name(data[1]);
	set_nickname(data[2]);
	set_phone_number(data[3]);
	set_darkest_secret(data[4]);
}

void	Contact::set_first_name(std::string first_name)
{
	this->_first_name = first_name;
	return ;
}

void	Contact::set_last_name(std::string last_name)
{
	this->_last_name = last_name;
	return ;
}

void	Contact::set_nickname(std::string nickname)
{
	this->_nickname = nickname;
	return ;
}

void	Contact::set_phone_number(std::string phone_number)
{
	this->_phone_number = phone_number;
	return ;
}

void	Contact::set_darkest_secret(std::string darkest_secret)
{
	this->_darkest_secret = darkest_secret;
	return ;
}

std::string	Contact::get_first_name(void)
{
	return (this->_first_name);
}

std::string	Contact::get_last_name(void)
{
	return (this->_last_name);
}

std::string	Contact::get_nickname(void)
{
	return (this->_nickname);
}

std::string	Contact::get_phone_number(void)
{
	return (this->_phone_number);
}

std::string	Contact::get_darkest_secret(void)
{
	return (this->_darkest_secret);
}
