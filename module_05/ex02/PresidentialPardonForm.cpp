/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:49:12 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/10 16:31:36 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : _target("")
{
	std::cout << "default PresidentialPardonForm constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("PresidentialPardonForm", 25, 5),
																			_target(target)
{
	std::cout << "PresidentialPardonForm constructor called with parameter \"target("
	<< this->getTarget() << ")\"" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src), _target(src._target)
{
	*this = src;
	std::cout << "copy PresidentialPardonForm constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "destructor PresidentialPardonForm \"" << this->getTarget() << "\" called" << std::endl;
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
	{
		;
	}
	std::cout << "assignment copy PresidentialPardonForm called" << std::endl;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw PresidentialPardonForm::FormIsNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw PresidentialPardonForm::GradeToExecuteIsNotEnoughtException();
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string const	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}
