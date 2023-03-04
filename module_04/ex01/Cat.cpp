/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:32:56 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/03 19:23:39 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal(), _brain(new Brain())
{
	setType("Cat");
	std::cout << "default Cat constructor called" << std::endl;
	return ;
}

Cat::Cat(Cat const &src) : Animal(src), _brain(new Brain(*src._brain))
{
	*this = src;
	std::cout << "copy Cat constructor called" << std::endl;
	return ;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "destructor Cat called" << std::endl;
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
