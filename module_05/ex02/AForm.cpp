/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:49:12 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/10 12:51:01 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name(""), _is_signed(false), _grade_to_sign(150), _grade_to_execute(150)
{
	if ((this->getGradeToSign() < 1) || (this->getGradeToExecute() < 1))
		throw AForm::GradeTooHighException();
	if ((this->getGradeToSign() > 150) || (this->getGradeToExecute() > 150))
		throw AForm::GradeTooLowException();
	std::cout << "default AForm constructor called. \"name(" << this->getName()
	<< ")\", \"grade_to_sign(" << this->getGradeToSign()
	<< ")\", and \"grade_to_execute(" << this->getGradeToExecute()
	<< ")\"" << std::endl;
	return ;
}

AForm::AForm(std::string const name, unsigned int const grade_to_sign,
									unsigned int const grade_to_execute) : _name(name),
																			_is_signed(false),
																			_grade_to_sign(grade_to_sign),
																			_grade_to_execute(grade_to_execute)
{
	if ((this->getGradeToSign() < 1) || (this->getGradeToExecute() < 1))
		throw AForm::GradeTooHighException();
	if ((this->getGradeToSign() > 150) || (this->getGradeToExecute() > 150))
		throw AForm::GradeTooLowException();
	std::cout << "AForm constructor called with parameters \"name(" << this->getName()
	<< ")\", \"grade_to_sign(" << this->getGradeToSign()
	<< ")\", and \"grade_to_execute(" << this->getGradeToExecute() << ")\""
	<< std::endl;
	return ;
}

AForm::AForm(AForm const &src) : _name(src._name),
								_grade_to_sign(src._grade_to_sign),
								_grade_to_execute(src._grade_to_execute)
{
	*this = src;
	std::cout << "copy AForm constructor called" << std::endl;
	return ;
}

AForm::~AForm(void)
{
	std::cout << "destructor AForm \"" << this->getName() << "\" called" << std::endl;
	return ;
}

AForm	&AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
		this->_is_signed = rhs.getIsSigned();
	std::cout << "assignment copy AForm called" << std::endl;
	return (*this);
}

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->setIsSigned(true);
	else
		throw AForm::GradeTooLowException();
	return ;
}

std::string const	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getIsSigned(void) const
{
	return (this->_is_signed);
}

unsigned int	AForm::getGradeToSign(void) const
{
	return (this->_grade_to_sign);
}

unsigned int	AForm::getGradeToExecute(void) const
{
	return (this->_grade_to_execute);
}

void	AForm::setIsSigned(bool is_signed)
{
	this->_is_signed = is_signed;
	return ;
}

std::ostream	&operator<<(std::ostream &out, AForm const &src)
{
	out << src.getName() << ", Aform grade_to_sign " << src.getGradeToSign()
	<< " and grade_to_execute " << src.getGradeToExecute()
	<< ". The Aform is" << (src.getIsSigned() ? " " : " not ") << "signed" << std::endl;
	return (out);
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("the grade is too high! ↗️ 💥");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("the grade is too low! ↘️ 💥");
}

const char	*AForm::FormIsNotSignedException::what(void) const throw()
{
	return ("the form is NOT signed! ⛔");
}

const char	*AForm::GradeToExecuteIsNotEnoughtException::what(void) const throw()
{
	return ("the grade is too low to execute! 👎");
}
