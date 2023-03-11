/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:49:12 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/11 13:27:19 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name(""), _grade(42)
{
	if (getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	if (getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "default Bureaucrat constructor called. \"grade(" << this->getGrade()
	<< ")\" and \"name(" << this->getName() << ")\"" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string const name, unsigned int grade) : _name(name), _grade(grade)
{
	if (getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	if (getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat constructor called with parameters \"grade(" << this->getGrade()
	<< ")\" and \"name(" << this->getName() << ")\"" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name)
{
	*this = src;
	std::cout << "copy Bureaucrat constructor called" << std::endl;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "destructor Bureaucrat \"" << this->getName() << "\" called" << std::endl;
	return ;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
		this->setGrade(rhs.getGrade());
	std::cout << "assignment copy Bureaucrat called" << std::endl;
	return (*this);
}

void	Bureaucrat::increment(void)
{
	this->setGrade(this->getGrade() - 1);
	if (this->getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	return ;
}

void	Bureaucrat::decrement(void)
{
	this->setGrade(this->getGrade() + 1);
	if (this->getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
	return ;
}

std::string const	Bureaucrat::getName(void) const
{
	return (this->_name);
}

void	Bureaucrat::setGrade(unsigned int grade)
{
	this->_grade = grade;
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("the grade is too high! ↗️ 💥");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("the grade is too low! ↘️ 💥");
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &src)
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << "." << std::endl;
	return (out);
}
