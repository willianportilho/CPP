/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:40:03 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/14 15:55:14 by wportilh         ###   ########.fr       */
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

	if (PhoneBook::amount_of_contacts == 8)
		index = 0;
	tmp.get_contact_data();
	contacts[PhoneBook::index].set_first_name(tmp.get_first_name());
	contacts[PhoneBook::index].set_last_name(tmp.get_last_name());
	contacts[PhoneBook::index].set_nickname(tmp.get_nickname());
	contacts[PhoneBook::index].set_phone_number(tmp.get_phone_number());
	contacts[PhoneBook::index].set_darkest_secret(tmp.get_darkest_secret());
	if (PhoneBook::amount_of_contacts < 8)
		PhoneBook::amount_of_contacts += 1;
	PhoneBook::index += 1;
}

int	PhoneBook::print_contact(int index)
{
	for (int i = 0; i < PhoneBook::amount_of_contacts; i++)
	{
		if ((i) == index)
		{
			std::cout << std::endl;
			std::cout << "first name: " << contacts[i].get_first_name() << std::endl;
			std::cout << "last name: " << contacts[i].get_last_name() << std::endl;
			std::cout << "nickname: " << contacts[i].get_nickname() << std::endl;
			std::cout << "phone number: " << contacts[i].get_phone_number() << std::endl;
			std::cout << "darkest secret: " << contacts[i].get_darkest_secret() << std::endl;
			std::cout << std::endl;
			return (true);
		}
	}
	std::cout << std::endl << "error: invalid index!" << std::endl << std::endl;
	return (false);
}

void	PhoneBook::print_one_contact(void)
{
	std::string	index;

	while (1)
	{
		if (!std::cin.eof())
		{
			std::cout << "Please, enter a index: ";
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
				if (print_contact(index[0] - '1') == true)
					return ;
			}
		}
	}
}

void	PhoneBook::format_data(std::string orig_data, std::string *new_data)
{
	if (orig_data.length() > 10)
	{
		*new_data = orig_data.substr(0, 9);
		new_data->append(".");
	}
	else
		*new_data = orig_data;
}

void	PhoneBook::print_phone_book(void)
{
	std::string	data[3];

	std::cout << std::endl;
	std::cout << std::right << std::setw(10) << "index" << "|";
	std::cout << std::right << std::setw(10) << "first name" << "|";
	std::cout << std::right << std::setw(10) << "last name" << "|";
	std::cout << std::right << std::setw(10) << "nickname";
	std::cout << std::endl;
	for (int i = 0; i < PhoneBook::amount_of_contacts; i++)
	{
		format_data(contacts[i].get_first_name(), &data[0]);
		format_data(contacts[i].get_last_name(), &data[1]);
		format_data(contacts[i].get_nickname(), &data[2]);
		std::cout << std::right << std::setw(10) << (i + 1) << "|";
		std::cout << std::right << std::setw(10) << data[0] << "|";
		std::cout << std::right << std::setw(10) << data[1] << "|";
		std::cout << std::right << std::setw(10) << data[2] << std::endl;
	}
	std::cout << std::endl;
}

void	PhoneBook::search_contact(void)
{
	if (!PhoneBook::amount_of_contacts)
	{
		std::cout << std::endl << "empty phone book!" << std::endl << std::endl;
		return ;
	}
	print_phone_book();
	print_one_contact();
}

int	PhoneBook::amount_of_contacts = 0;

int	PhoneBook::index = 0;
