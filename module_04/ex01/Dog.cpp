/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:32:56 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/03 20:43:06 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal(), _brain(new Brain())
{
	setType("Dog");
	std::cout << "default Dog constructor called" << std::endl;
	return ;
}

Dog::Dog(Dog const &src) : Animal(src), _brain(new Brain(*src._brain))
{
	*this = src;
	std::cout << "copy Dog constructor called" << std::endl;
	return ;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "destructor Dog called" << std::endl;
	return ;
}

Dog	&Dog::operator=(Dog const &rhs)
{
	if (this != &rhs)
	{
		// delete this->_brain;
		//this->_brain = new Brain();
		*this->_brain = *rhs._brain;
	}
	std::cout << "assignment copy Dog called" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof, Woof!!!" << std::endl;
}

void	Dog::setIdeas(std::string const idea, unsigned int const i)
{
	this->_brain->setIdeas(idea, i);
	return ;
}

std::string	Dog::getIdeas(unsigned int const i) const
{
	return (this->_brain->getIdeas(i));
}