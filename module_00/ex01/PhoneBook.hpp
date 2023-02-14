/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:34:07 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/14 15:23:38 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
# include "Contact.hpp"

class	PhoneBook
{
	public:

		PhoneBook(void);
		~PhoneBook(void);

		Contact contacts[8];
		void		add_contact(void);
		void		search_contact(void);
		void		print_phone_book(void);
		void		format_data(std::string orig_data, std::string *new_data);
		void		print_one_contact(void);
		int			print_contact(int index);
		static int	amount_of_contacts;
		static int	index;
};

#endif
