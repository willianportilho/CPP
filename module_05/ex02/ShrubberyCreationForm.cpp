/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:49:12 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/10 22:50:35 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm(), _target("")
{
	std::cout << "default ShrubberyCreationForm constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", 145, 137),
																			_target(target)
{
	std::cout << "ShrubberyCreationForm constructor called with parameter \"target("
	<< this->getTarget() << ")\"" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src), _target(src._target)
{
	*this = src;
	std::cout << "copy ShrubberyCreationForm constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "destructor ShrubberyCreationForm \"" << this->getTarget() << "\" called" << std::endl;
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
	{
		;
	}
	std::cout << "assignment copy ShrubberyCreationForm called" << std::endl;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw ShrubberyCreationForm::FormIsNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw ShrubberyCreationForm::GradeToExecuteIsNotEnoughtException();	
	std::cout << "               ,@@@@@@@," << std::endl;
    std::cout << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
    std::cout << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	std::cout << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	std::cout << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	std::cout << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	std::cout << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	std::cout << "       |o|        | |         | |" << std::endl;
	std::cout << "       |.|        | |         | |" << std::endl;
	std::cout << "jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
}

std::string const	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}
