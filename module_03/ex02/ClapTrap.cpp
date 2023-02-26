/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:27:37 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/26 19:32:03 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):	_name("🧗 Eldian"),
							_hit_points(10),
							_energy_points(10),
							_attack_damage(0)
{
	std::cout << "default ClapTrap (" << this->get_name() << ") constructor called"
	<< std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string const name):	_name(name),
											_hit_points(10),
											_energy_points(10),
											_attack_damage(0)
{
	std::cout << "named ClapTrap (" << this->get_name() << ") constructor called"
	<< std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &clap_trap)
{
	*this = clap_trap;
	std::cout << "copy ClapTrap (" << this->get_name() << ") constructor called"
	<< std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "destructor ClapTrap (" << this->get_name() << ") called"
	<< std::endl;
	return ;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &clap_trap)
{
	if (this != &clap_trap)
	{
		this->_name = clap_trap.get_name();
		this->_attack_damage = clap_trap.get_attack_damage();
		this->_energy_points = clap_trap.get_energy_points();
		this->_hit_points = clap_trap.get_hit_points();
	}
	std::cout << "assignment copy ClapTrap (" << this->get_name() << ") called"
	<< std::endl;
	return (*this);
}

int	ClapTrap::check_input(void)
{
	if ((this->_hit_points < 0) || (this->_attack_damage < 0) || (this->_energy_points < 0))
	{
		std::cout << "hit_points, attack damage and energy_points can't be negative"
		<< std::endl;
		return (false);
	}
	return (true);
}

void	ClapTrap::attack(const std::string& target)
{
	if (!check_input())
		return ;
	else if (!this->_hit_points)
	{
		std::cout << "ClapTrap \"" << this->_name
		<< "\" can no longer attack 😭. Hit points = \""
		<< this->_hit_points << "\". Is dead! 💀⚰️"
		<< std::endl;
	}
	else if (!this->_energy_points)
	{
		std::cout << "ClapTrap \"" << this->_name
		<< "\" can no longer attack 🙁. Energy points = \""
		<< this->_energy_points << "\". Is tired! 🥱🛏️"
		<< std::endl;
	}
	else
	{
		this->_energy_points--;
		std::cout << "ClapTrap \"" << this->_name
		<< "\" attacks 🤺 \"" << target
		<< "\", causing \"" << this->_attack_damage << "\" points of damage!"
		<< std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!check_input())
		return ;
	else if (!this->_hit_points)
	{
		std::cout << "ClapTrap \"" << this->_name
		<< "\" can no longer suffered more damage 😭. Hit points = \""
		<< this->_hit_points << "\". Is dead! 💀⚰️"
		<< std::endl;
	}
	else if (!this->_energy_points)
	{
		std::cout << "ClapTrap \"" << this->_name
		<< "\" can no longer suffered more damage 🙁. Energy points = \""
		<< this->_energy_points << "\". Is tired! 🥱🛏️"
		<< std::endl;
	}
	else
	{
		this->_hit_points -= amount;
		if (this->_hit_points < 0)
			this->_hit_points = 0;
		std::cout << "ClapTrap \"" << this->_name
		<< "\" suffered damage 😬 \""
		<< amount << "\" hit points back!"
		<< std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!check_input())
		return ;
	else if (!this->_hit_points)
	{
		std::cout << "ClapTrap \"" << this->_name
		<< "\" can no longer be repaired 😭. Hit points = \""
		<< this->_hit_points << "\". Is dead! 💀 ⚰️"
		<< std::endl;
	}
	else if (!this->_energy_points)
	{
		std::cout << "ClapTrap \"" << this->_name
		<< "\" can no longer be repaired 🙁. Energy points = \""
		<< this->_energy_points << "\". Is tired! 🥱 🛏️"
		<< std::endl;
	}
	else
	{
		this->_hit_points += amount;
		if (this->_hit_points < 0)
			this->_hit_points = 0;
		this->_energy_points--;
		std::cout << "ClapTrap \"" << this->_name 
		<< "\" was repaired 💊, getting \""
		<< amount << "\" hit points back!"
		<< std::endl;
	}
}
	
void	ClapTrap::set_name(std::string name)
{
	this->_name = name;
	return ;
}

void	ClapTrap::set_hit_points(int hit_points)
{
	this->_hit_points = hit_points;
	return ;
}

void	ClapTrap::set_energy_points(int energy_points)
{
	this->_energy_points = energy_points;
	return ;	
}

void	ClapTrap::set_attack_damage(int attack_damage)
{
	this->_attack_damage = attack_damage;
	return ;
}

std::string	ClapTrap::get_name(void) const
{
	return (this->_name);
}

int	ClapTrap::get_hit_points(void) const
{
	return (this->_hit_points);
}

int	ClapTrap::get_energy_points(void) const
{
	return (this->_energy_points);
}

int	ClapTrap::get_attack_damage(void) const
{
	return (this->_attack_damage);
}
