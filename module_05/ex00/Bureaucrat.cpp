/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:49:12 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/08 21:58:59 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name(""), _grade(42)
{
	if (getGrade() < 1)
		std::cout << "throw smallest number";
	if (getGrade() > 150)
		std::cout << "throw greatest number";
	std::cout << "default Bureaucrat constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(unsigned int grade, std::string const name) : _name(name), _grade(grade)
{
	if (getGrade() < 1)
		std::cout << "throw smallest number";
	if (getGrade() > 150)
		std::cout << "throw greatest number";
	std::cout << "Bureaucrat constructor called with parameters (grade and name)" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	*this = src;
	std::cout << "copy Bureaucrat constructor called" << std::endl;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "destructor Bureaucrat called" << std::endl;
	return ;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		;
	}
	std::cout << "assignment copy Bureaucrat called" << std::endl;
	return (*this);
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("error: GradeTooHighException: The grade is too high!");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("error: GradeTooLowException: The grade is too low!");
}

std::string const	Bureaucrat::getName(void)
{
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade(void)
{
	return (this->_grade);
}
