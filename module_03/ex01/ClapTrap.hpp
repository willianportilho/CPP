/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:26:09 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/25 21:26:54 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>
#include <string>

class	ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string const name);
		ClapTrap(ClapTrap const &clap_trap);
		~ClapTrap(void);
		ClapTrap				&operator=(ClapTrap const &clap_trap);
		std::string				get_name(void) const;
		int						get_hit_points(void) const;
		int						get_energy_points(void) const;
		int						get_attack_damage(void) const;
		void					set_name(std::string name);
		void					set_hit_points(int hit_points);
		void					set_energy_points(int energy_points);
		void					set_attack_damage(int attack_points);
		void					attack(const std::string& target);
		void					takeDamage(unsigned int amount);
		void					beRepaired(unsigned int amount);
		int						check_input(void);
	private:
		std::string				_name;
		int						_hit_points;
		int						_energy_points;
		int						_attack_damage;
};

#endif
