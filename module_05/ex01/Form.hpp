/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/09 19:56:22 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include <iostream>
#include <string>

class	Form
{
	public:
		Form(std::string const name);
		Form(Form const &src);
		~Form(void);
		Form				&operator=(Form const &rhs);
		std::string const	getName(void) const;
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
	private:
		Form(void); //????????????????????????????????????????????????????????????????????????????????????
		std::string const	_name;
};

std::ostream	&operator<<(std::ostream &out, Form const &src);

#endif
