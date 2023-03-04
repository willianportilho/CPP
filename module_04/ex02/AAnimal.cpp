/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:26:59 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/04 16:49:31 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	setType("AAnimal");
	std::cout << "default AAnimal constructor called" << std::endl;
	return ;
}

AAnimal::AAnimal(AAnimal const &src)
{
	*this = src;
	std::cout << "copy AAnimal constructor called" << std::endl;
	return ;
}

AAnimal::~AAnimal(void)
{
	std::cout << "destructor AAnimal called" << std::endl;
	return ;
}

AAnimal	&AAnimal::operator=(AAnimal const &rhs)
{
	if (this != &rhs)
		this->setType(rhs.getType());
	std::cout << "assignment copy AAnimal called" << std::endl;
	return (*this);
}

void	AAnimal::setType(std::string const type)
{
	this->_type = type;
	return ;
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}

void	AAnimal::makeSound(void) const
{
	std::cout << "trust me, \"AAnimal\" doesn't make a sound" << std::endl;
}
