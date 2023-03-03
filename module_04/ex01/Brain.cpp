/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:49:12 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/03 16:27:32 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
		this->setIdeas("", i);
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
	{
		for (int i = 0; i < 100; i++)
			this->setIdeas(rhs.getIdeas(i), i);
	}
	std::cout << "assignment copy Brain called" << std::endl;
	return (*this);
}

void	Brain::setIdeas(std::string const idea, unsigned int const i)
{
	if ((i < 100))
		this->_ideas[i] = idea;
	return ;
}

std::string	Brain::getIdeas(unsigned int const i) const
{
	if (i < 100)
		return (this->_ideas[i]);
	else
		return ("");
}
