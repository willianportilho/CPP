/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:49:12 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/09 19:56:29 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("")
{
	std::cout << "default Form constructor called. \"name(" << this->getName() << ")\"" << std::endl;
	return ;
}

Form::Form(std::string const name) : _name(name)
{
	std::cout << "Form constructor called with parameter \"name(" << this->getName() << ")\"" << std::endl;
	return ;
}

Form::Form(Form const &src) : _name(src._name)
{
	*this = src;
	std::cout << "copy Form constructor called" << std::endl;
	return ;
}

Form::~Form(void)
{
	std::cout << "destructor Form \"" << this->getName() << "\" called" << std::endl;
	return ;
}

Form	&Form::operator=(Form const &rhs)
{
	if (this != &rhs)
	{
		;
	}
	std::cout << "assignment copy Form called" << std::endl;
	return (*this);
}

std::string const	Form::getName(void) const
{
	return (this->_name);
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("error: The grade is too high! ↗️ 💥");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("error: The grade is too low! ↘️ 💥");
}

std::ostream	&operator<<(std::ostream &out, Form const &src)
{
	out << src.getName() << "." << std::endl;
	return (out);
}
