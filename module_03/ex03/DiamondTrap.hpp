/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:27:10 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/27 21:27:45 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(std::string const name);
		DiamondTrap(DiamondTrap const &clap_trap);
		~DiamondTrap(void);
		DiamondTrap	&operator=(DiamondTrap const &clap_trap);
		std::string	get_name(void) const;
		void		set_name(std::string name);
		void		attack(const std::string& target);
		void		whoAmI();
	private:
		std::string	_name;
};

#endif
