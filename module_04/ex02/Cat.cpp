/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:32:56 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/04 19:32:16 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal(), _brain(new Brain())
{
	setType("Cat");
	std::cout << "default Cat constructor called" << std::endl;
	return ;
}

Cat::Cat(Cat const &src) : AAnimal(src), _brain(new Brain(*src._brain))
{
	*this = src;
	std::cout << "copy Cat constructor called" << std::endl;
	return ;
}

Cat::~Cat(void)
{
	std::cout << "destructor Cat called" << std::endl;
	delete this->_brain;
	return ;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	if (this != &rhs)
	{
		//delete this->_brain;
		//this->_brain = new Brain();
		*this->_brain = *rhs._brain;
	}
	std::cout << "assignment copy Cat called" << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow!!!" << std::endl;
}

void	Cat::setIdeas(std::string const idea, unsigned int const i)
{
	this->_brain->setIdeas(idea, i);
	return ;
}

std::string	Cat::getIdeas(unsigned int const i) const
{
	return (this->_brain->getIdeas(i));
}
