/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:34:07 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/14 17:30:03 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <iomanip>
# include "Contact.hpp"

class	PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void		add_contact(void);
		void		search_contact(void);
	private:
		Contact		_contacts[8];
		void		_print_phone_book(void);
		void		_format_data(std::string orig_data, std::string *new_data);
		void		_print_one_contact(void);
		int			_print_contact(int index);
		static int	_amount_of_contacts;
		static int	_index;
};

#endif
