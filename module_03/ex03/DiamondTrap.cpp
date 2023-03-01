/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:27:13 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/01 17:50:11 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(),
									ScavTrap(),
									FragTrap()
{
	ScavTrap::set_energy_points(50);
	this->set_name("♨️  Balrog");
	this->set_hit_points(FragTrap::get_hit_points());
	this->set_energy_points(ScavTrap::get_energy_points());
	this->set_attack_damage(FragTrap::get_attack_damage());
	ClapTrap::set_name(this->get_name() + "_clap_name");
	std::cout << "default DiamondTrap ("
	<< this->get_name() << ") constructor called"
	<< std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string const name) : ClapTrap(name + "_clap_name"),
													ScavTrap(name + "_clap_name"),
													FragTrap(name + "_clap_name")
{
	ScavTrap::set_energy_points(50);
	this->set_name(name);
	this->set_hit_points(FragTrap::get_hit_points());
	this->set_energy_points(ScavTrap::get_energy_points());
	this->set_attack_damage(FragTrap::get_attack_damage());
	ClapTrap::set_name(this->get_name() + "_clap_name");
	std::cout << "named DiamondTrap constructor ("
	<< this->get_name() << ") called"
	<< std::endl;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const &diamond_trap) : ClapTrap(diamond_trap),
															ScavTrap(diamond_trap),
															FragTrap(diamond_trap)
{
	*this = diamond_trap;
	std::cout << "copy DiamondTrap ("
	<< this->get_name() << ") constructor called"
	<< std::endl;
	return ;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "destructor DiamondTrap ("
	<< this->get_name() << ") called"
	<< std::endl;
	return ;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &diamond_trap)
{
	if (this != &diamond_trap)
	{
		this->set_name(diamond_trap.get_name());
		this->set_attack_damage(diamond_trap.get_attack_damage());
		this->set_energy_points(diamond_trap.get_energy_points());
		this->set_hit_points(diamond_trap.get_hit_points());
		ClapTrap::set_name(this->get_name() + "_clap_name");
	}
	std::cout << "assignment copy DiamondTrap ("
	<< this->get_name() << ") called"
	<< std::endl;
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My name is \"" << this->_name
	<< "\", and my ClapTrap name is \"" << ClapTrap::get_name()
	<< "\"." << std::endl;
}

void	DiamondTrap::set_name(std::string name)
{
	this->_name = name;
	return ;
}

std::string	DiamondTrap::get_name(void) const
{
	return (this->_name);
}
