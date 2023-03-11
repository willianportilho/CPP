/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:26:57 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/11 17:25:29 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

class	Intern
{
	public:
		Intern(void);
		Intern(Intern const &src);
		~Intern(void);
		Intern	&operator=(Intern const &rhs);
		AForm	*makeForm(std::string const name, std::string const target);
		class	FormDoesNotExistException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

#endif
