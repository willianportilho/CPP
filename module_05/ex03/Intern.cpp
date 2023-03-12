/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:26:53 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/11 21:33:14 by wportilh         ###   ########.fr       */
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

AForm	*Intern::Shrubbery(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::Robotomy(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::President(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string const name, std::string const target)
{
	std::string const	formType[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm *(Intern::*form[3])(std::string const &target) = {&Intern::Shrubbery, &Intern::Robotomy, &Intern::President};

	for (int i = 0; i < 3; i++)
	{
		if (name == formType[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return ((this->*form[i])(target));
		}
	}
	throw Intern::FormDoesNotExistException();
}

const char	*Intern::FormDoesNotExistException::what(void) const throw()
{
	return ("error: the form does not exist! ❌");
}
