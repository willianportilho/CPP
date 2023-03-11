/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:49:12 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/10 16:31:36 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : _target("")
{
	std::cout << "default RobotomyRequestForm constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("ShrubberyCreationForm", 72, 45),
																			_target(target)
{
	std::cout << "RobotomyRequestForm constructor called with parameter \"target("
	<< this->getTarget() << ")\"" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src), _target(src._target)
{
	*this = src;
	std::cout << "copy RobotomyRequestForm constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "destructor RobotomyRequestForm \"" << this->getTarget() << "\" called" << std::endl;
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
	{
		;
	}
	std::cout << "assignment copy RobotomyRequestForm called" << std::endl;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw RobotomyRequestForm::FormIsNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw RobotomyRequestForm::GradeToExecuteIsNotEnoughtException();
	std::cout << "~~~*******~~~~~~~ dRiLlInG nOiSeS ~~~*******~~~~~~~" << std::endl;
	std::srand(time(0));
	if (std::rand() % 2)
		std::cout << "\"" << this->getTarget() << "\" has been robotomized successfully 🤖✅" << std::endl;
	else
		std::cout << "unfortunately \"" << this->getTarget() << "\" robotomy failed 🤖❌" << std::endl;
}

std::string const	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}
