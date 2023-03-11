/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:26:53 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/11 17:45:27 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "default Intern constructor called" << std::endl;
	return ;
}

Intern::Intern(Intern const &src)
{
	
	(void)src;
	std::cout << "copy Intern constructor called" << std::endl;
	return ;
}

Intern::~Intern(void)
{
	std::cout << "destructor Intern called" << std::endl;
	return ;
}

Intern	&Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	std::cout << "assignment copy Intern called" << std::endl;
	return (*this);
}



AForm	*Intern::makeForm(std::string const name, std::string const target)
{
	int					formIndex = -1;
	std::string const	formType[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	for (int i = 0; i < 3; i++)
	{
		if (name == formType[i])
		{
			std::cout << "Aqui!" << std::endl;
			formIndex = i;
			break;
		}
	}
	switch (formIndex)
	{
		case 0:
			std::cout << "Intern creates " << name << std::endl;
			return (new ShrubberyCreationForm(target));
		case 1:
			std::cout << "Intern creates " << name << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern creates " << name << std::endl;
			return (new PresidentialPardonForm(target));
		default:
			throw Intern::FormDoesNotExistException();
	}
}

const char	*Intern::FormDoesNotExistException::what(void) const throw()
{
	return ("error: the form does not exist! ❌");
}
