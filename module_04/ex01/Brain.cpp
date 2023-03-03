/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:49:12 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/03 13:50:27 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	setType("Brain");
	std::cout << "default Brain constructor called" << std::endl;
	return ;
}

Brain::Brain(Brain const &src)
{
	*this = src;
	std::cout << "copy Brain constructor called" << std::endl;
	return ;
}

Brain::~Brain(void)
{
	std::cout << "destructor Brain called" << std::endl;
	return ;
}

Brain	&Brain::operator=(Brain const &rhs)
{
	if (this != &rhs)
		this->setType(rhs.getType());
	std::cout << "assignment copy Brain called" << std::endl;
	return (*this);
}

void	Brain::setType(std::string const type)
{
	this->_type = type;
	return ;
}

std::string	Brain::getType(void) const
{
	return (this->_type);
}
