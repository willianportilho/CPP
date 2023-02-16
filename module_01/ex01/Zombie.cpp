/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:44:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/16 17:23:40 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Fortunately, the treasured zombie nº" << _number_constructed_zombie << " was constructed. :("
	<< std::endl;
	_number_constructed_zombie += 1;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << "Unfortunately, the treasured zombie '" << this->_name
	<< "', nº" << _number_destroyed_zombie << " was destroyed. :("
	<< std::endl;
	_number_destroyed_zombie += 1;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string zombie_name)
{
	this->_name = zombie_name;
	return ;
}

int	Zombie::_number_constructed_zombie = 1;
int	Zombie::_number_destroyed_zombie = 1;