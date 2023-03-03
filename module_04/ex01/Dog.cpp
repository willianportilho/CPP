/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:32:56 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/03 13:26:29 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	setType("Dog");
	std::cout << "default Dog constructor called" << std::endl;
	return ;
}

Dog::Dog(Dog const &src) : Animal(src)
{
	*this = src;
	std::cout << "copy Dog constructor called" << std::endl;
	return ;
}

Dog::~Dog(void)
{
	std::cout << "destructor Dog called" << std::endl;
	return ;
}

Dog	&Dog::operator=(Dog const &rhs)
{
	if (this != &rhs)
		this->setType(rhs.getType());
	std::cout << "assignment copy Dog called" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof, Woof!!!" << std::endl;
}
