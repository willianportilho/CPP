/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:34:07 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/14 12:03:18 by wportilh         ###   ########.fr       */
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
		static int	amount_of_contacts;
		static int	index;
};

#endif
