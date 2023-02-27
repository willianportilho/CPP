/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:11:55 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/27 14:29:18 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->set_name("🧗 Eldian");
	this->set_hit_points(100);
	this->set_energy_points(50);
	this->set_attack_damage(20);
	std::cout << "default ScavTrap ("
	<< this->get_name() << ") constructor called"
	<< std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string const name) : ClapTrap(name)
{
	this->set_name(name);
	this->set_hit_points(100);
	this->set_energy_points(50);
	this->set_attack_damage(20);
	std::cout << "named ScavTrap constructor ("
	<< this->get_name() << ") called"
	<< std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &scav_trap) : ClapTrap(scav_trap)
{
	*this = scav_trap;
	std::cout << "copy ScavTrap ("
	<< this->get_name() << ") constructor called"
	<< std::endl;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "destructor ScavTrap ("
	<< this->get_name() << ") called"
	<< std::endl;
	return ;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &scav_trap)
{
	if (this != &scav_trap)
	{
		this->set_name(scav_trap.get_name());
		this->set_attack_damage(scav_trap.get_attack_damage());
		this->set_energy_points(scav_trap.get_energy_points());
		this->set_hit_points(scav_trap.get_hit_points());
	}
	std::cout << "assignment copy ScavTrap ("
	<< this->get_name() << ") called"
	<< std::endl;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (!check_input())
		return ;
	else if (!this->get_hit_points())
	{
		std::cout << "ScavTrap \"" << this->get_name()
		<< "\" can no longer attack 😩. Hit points = \""
		<< this->get_hit_points() << "\". Is dead! 💀⚱"
		<< std::endl;
	}
	else if (!this->get_energy_points())
	{
		std::cout << "ScavTrap \"" << this->get_name()
		<< "\" can no longer attack 😞. Energy points = \""
		<< this->get_energy_points() << "\". Is tired! 😴🛏️"
		<< std::endl;
	}
	else
	{
		this->set_energy_points(get_energy_points() - 1);
		std::cout << "ScavTrap \"" << this->get_name()
		<< "\" attacks 🤜 \"" << target
		<< "\", causing \"" << this->get_attack_damage()
		<< "\" points of damage!"
		<< std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	if (!check_input())
		return ;
	else if (!this->get_hit_points())
	{
		std::cout << "ScavTrap \"" << this->get_name()
		<< "\" can no longer be in Gate keeper mode 😭. Hit points = \""
		<< this->get_hit_points() << "\". Is dead! 💀⚰️"
		<< std::endl;
	}
	else if (!this->get_energy_points())
	{
		std::cout << "ScavTrap \"" << this->get_name()
		<< "\" can no longer be in Gate keeper mode 🙁. Energy points = \""
		<< this->get_energy_points() << "\". Is tired! 🥱🛏️"
		<< std::endl;
	}
	else
	{
		std::cout
		<< "ScavTrap \""
		<< this->get_name()
		<< "\", in is now in Gate keeper mode."
		<< std::endl;
	}
}
