/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:32:56 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/03 13:26:34 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	setType("Cat");
	std::cout << "default Cat constructor called" << std::endl;
	return ;
}

Cat::Cat(Cat const &src) : Animal(src)
{
	*this = src;
	std::cout << "copy Cat constructor called" << std::endl;
	return ;
}

Cat::~Cat(void)
{
	std::cout << "destructor Cat called" << std::endl;
	return ;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	if (this != &rhs)
		this->setType(rhs.getType());
	std::cout << "assignment copy Cat called" << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow!!!" << std::endl;
}
