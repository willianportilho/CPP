/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:26:59 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/04 13:03:27 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	setType("Animal");
	std::cout << "default Animal constructor called" << std::endl;
	return ;
}

Animal::Animal(Animal const &src)
{
	*this = src;
	std::cout << "copy Animal constructor called" << std::endl;
	return ;
}

Animal::~Animal(void)
{
	std::cout << "destructor Animal called" << std::endl;
	return ;
}

Animal	&Animal::operator=(Animal const &rhs)
{
	if (this != &rhs)
		this->setType(rhs.getType());
	std::cout << "assignment copy Animal called" << std::endl;
	return (*this);
}

void	Animal::setType(std::string const type)
{
	this->_type = type;
	return ;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "trust me, \"Animal\" doesn't make a sound" << std::endl;
}
