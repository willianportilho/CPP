/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:19:30 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/16 22:24:14 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"
#include <iostream>
#include <string>

class	HumanA
{
	public:
		HumanA(std::string name, Weapon &club);
		~HumanA(void);
		void	attack(void);
	private:
		Weapon		&_club;
		std::string	_name;
};

#endif
