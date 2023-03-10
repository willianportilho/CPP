/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:49:12 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/09 21:22:29 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name(""), _grade_to_sign(150), _grade_to_execute(150)
{
	std::cout << "default Form constructor called. \"name(" << this->getName() << ")\"" << std::endl;
	return ;
}

Form::Form(std::string const name, unsigned const grade_to_sign,
									unsigned int const grade_to_execute) : _name(name),
																			_grade_to_sign(grade_to_sign),
																			_grade_to_execute(grade_to_execute)
{
	(void)grade_to_execute;
	(void)grade_to_sign;
	(void)name;
	std::cout << "Form constructor called with parameter \"name(" << this->getName() << ")\"" << std::endl;
	return ;
}

Form::Form(Form const &src) : _name(src._name),
							_grade_to_sign(src._grade_to_sign),
							_grade_to_execute(src._grade_to_execute)
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
		*this = rhs;
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
