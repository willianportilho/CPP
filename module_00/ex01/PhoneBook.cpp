/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:40:03 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/14 17:56:56 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::add_contact(void)
{
	Contact tmp;

	tmp.get_contact_data();
	if (PhoneBook::_index == 8)
		PhoneBook::_index = 0;
	_contacts[PhoneBook::_index].set_first_name(tmp.get_first_name());
	_contacts[PhoneBook::_index].set_last_name(tmp.get_last_name());
	_contacts[PhoneBook::_index].set_nickname(tmp.get_nickname());
	_contacts[PhoneBook::_index].set_phone_number(tmp.get_phone_number());
	_contacts[PhoneBook::_index].set_darkest_secret(tmp.get_darkest_secret());
	if (PhoneBook::_amount_of_contacts < 8)
		PhoneBook::_amount_of_contacts += 1;
	PhoneBook::_index += 1;
	
}

int	PhoneBook::_print_contact(int index)
{
	for (int i = 0; i < PhoneBook::_amount_of_contacts; i++)
	{
		if ((i) == index)
		{
			std::cout << std::endl;
			std::cout << "first name: " << _contacts[i].get_first_name() << std::endl;
			std::cout << "last name: " << _contacts[i].get_last_name() << std::endl;
			std::cout << "nickname: " << _contacts[i].get_nickname() << std::endl;
			std::cout << "phone number: " << _contacts[i].get_phone_number() << std::endl;
			std::cout << "darkest secret: " << _contacts[i].get_darkest_secret() << std::endl;
			std::cout << std::endl;
			return (true);
		}
	}
	std::cout << std::endl << "error: invalid index!" << std::endl << std::endl;
	return (false);
}

void	PhoneBook::_print_one_contact(void)
{
	std::string	index;

	while (1)
	{
		if (!std::cin.eof())
		{
			std::cout << "Please, enter a index: " << std::endl;
			std::getline(std::cin, index);
		}
		if (std::cin.eof())
			{
				std::cout << std::endl;
				return ;
			}
		if (index.length())
		{
			if (index.length() > 1)
				std::cout << std::endl << "error: invalid index!" << std::endl << std::endl;
			else
			{
				if (_print_contact(index[0] - '1') == true)
					return ;
			}
		}
	}
}

void	PhoneBook::_format_data(std::string orig_data, std::string *new_data)
{
	if (orig_data.length() > 10)
	{
		*new_data = orig_data.substr(0, 9);
		new_data->append(".");
	}
	else
		*new_data = orig_data;
}

void	PhoneBook::_print_phone_book(void)
{
	std::string	data[3];

	std::cout << std::endl;
	std::cout << std::right << std::setw(10) << "index" << "|";
	std::cout << std::right << std::setw(10) << "first name" << "|";
	std::cout << std::right << std::setw(10) << "last name" << "|";
	std::cout << std::right << std::setw(10) << "nickname";
	std::cout << std::endl;
	for (int i = 0; i < PhoneBook::_amount_of_contacts; i++)
	{
		_format_data(_contacts[i].get_first_name(), &data[0]);
		_format_data(_contacts[i].get_last_name(), &data[1]);
		_format_data(_contacts[i].get_nickname(), &data[2]);
		std::cout << std::right << std::setw(10) << (i + 1) << "|";
		std::cout << std::right << std::setw(10) << data[0] << "|";
		std::cout << std::right << std::setw(10) << data[1] << "|";
		std::cout << std::right << std::setw(10) << data[2] << std::endl;
	}
	std::cout << std::endl;
}

void	PhoneBook::search_contact(void)
{
	if (!PhoneBook::_amount_of_contacts)
	{
		std::cout << std::endl << "empty phone book!" << std::endl << std::endl;
		return ;
	}
	_print_phone_book();
	_print_one_contact();
}

int	PhoneBook::_amount_of_contacts = 0;

int	PhoneBook::_index = 0;
