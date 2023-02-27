/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:33:05 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/27 17:50:56 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->set_name("♨️  Balrog");
	this->set_hit_points(100);
	this->set_energy_points(100);
	this->set_attack_damage(30);
	std::cout << "default FragTrap ("
	<< this->get_name() << ") constructor called"
	<< std::endl;
	return ;
}

FragTrap::FragTrap(std::string const name) : ClapTrap(name)
{
	this->set_name(name);
	this->set_hit_points(100);
	this->set_energy_points(100);
	this->set_attack_damage(30);
	std::cout << "named FragTrap constructor ("
	<< this->get_name() << ") called"
	<< std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &frag_trap) : ClapTrap(frag_trap)
{
	*this = frag_trap;
	std::cout << "copy FragTrap ("
	<< this->get_name() << ") constructor called"
	<< std::endl;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "destructor FragTrap ("
	<< this->get_name() << ") called"
	<< std::endl;
	return ;
}

FragTrap	&FragTrap::operator=(FragTrap const &frag_trap)
{
	if (this != &frag_trap)
	{
		this->set_name(frag_trap.get_name());
		this->set_attack_damage(frag_trap.get_attack_damage());
		this->set_energy_points(frag_trap.get_energy_points());
		this->set_hit_points(frag_trap.get_hit_points());
	}
	std::cout << "assignment copy FragTrap ("
	<< this->get_name() << ") called"
	<< std::endl;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	if (!check_input())
		return ;
	else if (!this->get_hit_points())
	{
		std::cout << "FragTrap \"" << this->get_name()
		<< "\" can no longer display a positive high five, guys 😭. Hit points: \""
		<< this->get_hit_points() << "\". Is dead! 💀⚰️"
		<< std::endl;
	}
	else if (!this->get_energy_points())
	{
		std::cout << "FragTrap \"" << this->get_name()
		<< "\" can no longer display a positive high fives, guys 🙁. Energy points: \""
		<< this->get_energy_points() << "\". Is tired! 🥱🛏️"
		<< std::endl;
	}
	else
	{
		std::cout
		<< "FragTrap \""
		<< this->get_name()
		<< "\": High five, guys! 🙏🏻"
		<< std::endl;
	}
}
