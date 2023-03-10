/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:49:12 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/10 12:32:46 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name(""), _is_signed(false), _grade_to_sign(150), _grade_to_execute(150)
{
	if ((this->getGradeToSign() < 1) || (this->getGradeToExecute() < 1))
		throw Form::GradeTooHighException();
	if ((this->getGradeToSign() > 150) || (this->getGradeToExecute() > 150))
		throw Form::GradeTooLowException();
	std::cout << "default Form constructor called. \"name(" << this->getName()
	<< ")\", \"grade_to_sign(" << this->getGradeToSign()
	<< ")\", and \"grade_to_execute(" << this->getGradeToExecute()
	<< ")\"" << std::endl;
	return ;
}

Form::Form(std::string const name, unsigned const grade_to_sign,
									unsigned int const grade_to_execute) : _name(name),
																			_is_signed(false),
																			_grade_to_sign(grade_to_sign),
																			_grade_to_execute(grade_to_execute)
{
	if ((this->getGradeToSign() < 1) || (this->getGradeToExecute() < 1))
		throw Form::GradeTooHighException();
	if ((this->getGradeToSign() > 150) || (this->getGradeToExecute() > 150))
		throw Form::GradeTooLowException();
	std::cout << "Form constructor called with parameters \"name(" << this->getName()
	<< ")\", \"grade_to_sign(" << this->getGradeToSign()
	<< ")\", and \"grade_to_execute(" << this->getGradeToExecute() << ")\""
	<< std::endl;
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
		this->_is_signed = rhs.getIsSigned();
	std::cout << "assignment copy Form called" << std::endl;
	return (*this);
}

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->setIsSigned(true);
	else
		throw Form::GradeTooLowException();
	return ;
}

std::string const	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getIsSigned(void) const
{
	return (this->_is_signed);
}

unsigned int	Form::getGradeToSign(void) const
{
	return (this->_grade_to_sign);
}

unsigned int	Form::getGradeToExecute(void) const
{
	return (this->_grade_to_execute);
}

void	Form::setIsSigned(bool is_signed)
{
	this->_is_signed = is_signed;
	return ;
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("the grade is too high! ↗️ 💥");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("the grade is too low! ↘️ 💥");
}

std::ostream	&operator<<(std::ostream &out, Form const &src)
{
	out << src.getName() << ", form grade_to_sign " << src.getGradeToSign()
	<< " and grade_to_execute " << src.getGradeToExecute() << "." << std::endl;
	return (out);
}
