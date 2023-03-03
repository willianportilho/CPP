/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:32:56 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/02 21:45:13 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	setType("WrongCat");
	std::cout << "default WrongCat constructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
	*this = src;
	std::cout << "copy WrongCat constructor called" << std::endl;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << "destructor WrongCat called" << std::endl;
	return ;
}

WrongCat	&WrongCat::operator=(WrongCat const &rhs)
{
	if (this != &rhs)
		this->setType(rhs.getType());
	std::cout << "assignment copy WrongCat called" << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow!!!" << std::endl;
}
